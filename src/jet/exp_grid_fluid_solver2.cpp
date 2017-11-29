// Copyright (c) 2017 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <pch.h>

#include <core_api_grid_fluid_solver_ispc_kernels_ispc.h>

#include <jet/core_api_array.h>
#include <jet/core_api_grid_fluid_solver.h>
#include <jet/exp_grid_fluid_solver2.h>

using namespace jet;
using namespace experimental;
using namespace core;

#define IX(i, j) ((i) + (N + 2) * (j))
#define FOR_EACH_CELL          \
    for (i = 1; i <= N; i++) { \
        for (j = 1; j <= N; j++) {
#define END_FOR \
    }           \
    }

namespace {

void addSource(size_t N, float* x, float* s, float dt) {
    BufferView xView = BufferViewBuilder()
                           .withDevice(Device::kIspc)
                           .withDataType(DataType::kFloat32)
                           .withBuffer(x)
                           .withShape({N + 2, N + 2})
                           .build();
    BufferView sView =
        BufferViewBuilder().withView(xView).withBuffer(s).build();
    BufferView dtView = BufferViewBuilder()
                            .withView(xView)
                            .withBuffer(&dt)
                            .withShape({1})
                            .build();

    // x = dt * s + x
    axpy(dtView, sView, xView, &xView);
}

void setBoundaryCondition(size_t N, int b, float* x) {
#if 0
    BufferView xView = BufferViewBuilder()
                           .withDevice(Device::kCpu)
                           .withDataType(DataType::kFloat32)
                           .withBuffer(x)
                           .withShape({N + 2, N + 2})
                           .build();
    setBoundaryCondition(xView, b);
#else
    ::ispc::setBoundaryCondition(N, b, x);
#endif
}

void solveLinearSystem(size_t N, int b, float* x, float* x0, float* buffer,
                       float a, float c) {
#if 0
    size_t i, j, k;

    for (k = 0; k < 40; k++) {
        FOR_EACH_CELL
        buffer[IX(i, j)] =
            (x0[IX(i, j)] + a * (x[IX(i - 1, j)] + x[IX(i + 1, j)] +
                                 x[IX(i, j - 1)] + x[IX(i, j + 1)])) /
            c;
        END_FOR
        setBoundaryCondition(N, b, buffer);
        std::swap(buffer, x);
    }
#elif 0
    BufferView xView = BufferViewBuilder()
                           .withDevice(Device::kCpu)
                           .withDataType(DataType::kFloat32)
                           .withBuffer(x)
                           .withShape({N + 2, N + 2})
                           .build();
    BufferView x0View =
        BufferViewBuilder().withView(xView).withBuffer(x0).build();
    BufferView bufferView =
        BufferViewBuilder().withView(xView).withBuffer(buffer).build();
    solveLinearSystem(xView, x0View, bufferView, a, c, b);
#else
    ::ispc::solveLinearSystem(N, b, x, x0, buffer, a, c);
#endif
}

void diffuse(size_t N, int b, float* x, float* x0, float* buffer, float diff,
             float dt) {
    float a = dt * diff * N * N;
    solveLinearSystem(N, b, x, x0, buffer, a, 1 + 4 * a);
}

void advect(size_t N, int b, float* d, float* d0, float* u, float* v,
            float dt) {
    size_t i, j, i0, j0, i1, j1;
    float x, y, s0, t0, s1, t1, dt0;

    dt0 = dt * N;
    FOR_EACH_CELL
    x = i - dt0 * u[IX(i, j)];
    y = j - dt0 * v[IX(i, j)];
    if (x < 0.5f) {
        x = 0.5f;
    }
    if (x > N + 0.5f) {
        x = N + 0.5f;
    }
    i0 = (size_t)x;
    i1 = i0 + 1;
    if (y < 0.5f) {
        y = 0.5f;
    }
    if (y > N + 0.5f) {
        y = N + 0.5f;
    }
    j0 = (size_t)y;
    j1 = j0 + 1;
    s1 = x - i0;
    s0 = 1 - s1;
    t1 = y - j0;
    t0 = 1 - t1;
    d[IX(i, j)] = s0 * (t0 * d0[IX(i0, j0)] + t1 * d0[IX(i0, j1)]) +
                  s1 * (t0 * d0[IX(i1, j0)] + t1 * d0[IX(i1, j1)]);
    END_FOR
    setBoundaryCondition(N, b, d);
}

void project(size_t N, float* u, float* v, float* p, float* div,
             float* buffer) {
    size_t i, j;

    FOR_EACH_CELL
    div[IX(i, j)] = -0.5f *
                    (u[IX(i + 1, j)] - u[IX(i - 1, j)] + v[IX(i, j + 1)] -
                     v[IX(i, j - 1)]) /
                    N;
    p[IX(i, j)] = 0;
    END_FOR
    setBoundaryCondition(N, 0, div);
    setBoundaryCondition(N, 0, p);

    solveLinearSystem(N, 0, p, div, buffer, 1, 4);

    FOR_EACH_CELL
    u[IX(i, j)] -= 0.5f * N * (p[IX(i + 1, j)] - p[IX(i - 1, j)]);
    v[IX(i, j)] -= 0.5f * N * (p[IX(i, j + 1)] - p[IX(i, j - 1)]);
    END_FOR
    setBoundaryCondition(N, 1, u);
    setBoundaryCondition(N, 2, v);
}

void densityStep(size_t N, float* x, float* x0, float* u, float* v,
                 float* buffer, float diff, float dt) {
    addSource(N, x, x0, dt);
    std::swap(x0, x);
    diffuse(N, 0, x, x0, buffer, diff, dt);
    std::swap(x0, x);
    advect(N, 0, x, x0, u, v, dt);
}

void velocityStep(size_t N, float* u, float* v, float* u0, float* v0,
                  float* buffer, float visc, float dt) {
    addSource(N, u, u0, dt);
    addSource(N, v, v0, dt);
    std::swap(u0, u);
    diffuse(N, 1, u, u0, buffer, visc, dt);
    std::swap(v0, v);
    diffuse(N, 2, v, v0, buffer, visc, dt);
    project(N, u, v, u0, v0, buffer);
    std::swap(u0, u);
    std::swap(v0, v);
    advect(N, 1, u, u0, u0, v0, dt);
    advect(N, 2, v, v0, u0, v0, dt);
    project(N, u, v, u0, v0, buffer);
}

}  // namespace

GridFluidSolver2::GridFluidSolver2() {
}

GridFluidSolver2::~GridFluidSolver2() {
}

void GridFluidSolver2::resizeGrid(const Size2& newSize,
                                  const Vector2D& newGridSpacing,
                                  const Vector2D& newGridOrigin) {
    UNUSED_VARIABLE(newGridSpacing);
    UNUSED_VARIABLE(newGridOrigin);

    _u.resize(newSize, 0.0f);
    _uTemp.resize(newSize, 0.0f);
    _v.resize(newSize, 0.0f);
    _vTemp.resize(newSize, 0.0f);
    _den.resize(newSize, 0.0f);
    _denTemp.resize(newSize, 0.0f);
    _buffer.resize(newSize, 0.0f);
}

ConstArrayAccessor2<float> GridFluidSolver2::density() const {
    return _den.constAccessor();
}

ArrayAccessor2<float> GridFluidSolver2::density() {
    return _den.accessor();
}

ArrayAccessor2<float> GridFluidSolver2::uSource() {
    return _uTemp.accessor();
}

ArrayAccessor2<float> GridFluidSolver2::vSource() {
    return _vTemp.accessor();
}

ArrayAccessor2<float> GridFluidSolver2::densitySource() {
    return _denTemp.accessor();
}

void GridFluidSolver2::onAdvanceTimeStep(double timeIntervalInSeconds) {
    size_t N = _u.size().x - 2;
    float visc = 0.0f;
    float diff = 0.0f;
    float dt = (float)timeIntervalInSeconds;

    velocityStep(N, _u.data(), _v.data(), _uTemp.data(), _vTemp.data(),
                 _buffer.data(), visc, dt);
    densityStep(N, _den.data(), _denTemp.data(), _u.data(), _v.data(),
                _buffer.data(), diff, dt);
}
