// Copyright (c) 2017 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <pch.h>

#include <core_api_utils.h>

#include <jet/parallel.h>

#define I(i, j) ((i) + (w) * (j))

namespace jet {

namespace core {

namespace internal {

namespace cpu {

void setBoundaryCondition(BufferView input, int mode);

struct SetBoundaryConditionOperator
    : public DimDispatcher<SetBoundaryConditionOperator> {
    template <typename T>
    void computeTyped2(T* p, const size_t w, const size_t h, int mode) const {
        T* rowDst1 = p;
        T* rowDst2 = p + (h - 1) * w;
        const T* rowSrc1 = rowDst1 + w;
        const T* rowSrc2 = rowDst2 - w;

        for (size_t i = 1; i < w - 1; ++i) {
            rowDst1[i] = (mode == 2) ? -rowSrc1[i] : rowSrc1[i];
            rowDst2[i] = (mode == 2) ? -rowSrc2[i] : rowSrc2[i];
        }

        for (size_t j = 1; j < h - 1; ++j) {
            T* colDst1 = p + j * w;
            T* colDst2 = p + (w - 1) + j * w;
            const T* colSrc1 = colDst1 + 1;
            const T* colSrc2 = colDst2 - 1;

            colDst1[0] = (mode == 1) ? -colSrc1[0] : colSrc1[0];
            colDst2[0] = (mode == 1) ? -colSrc2[0] : colSrc2[0];
        }

        p[I(0, 0)] = 0.5f * (p[I(1, 0)] + p[I(0, 1)]);
        p[I(0, h - 1)] = 0.5f * (p[I(1, h - 1)] + p[I(0, h - 2)]);
        p[I(w - 1, 0)] = 0.5f * (p[I(w - 2, 0)] + p[I(w - 1, 1)]);
        p[I(w - 1, h - 1)] = 0.5f * (p[I(w - 2, h - 1)] + p[I(w - 1, h - 2)]);
    }

    template <typename T>
    void computeTyped1(BufferView input, int mode) const {
        UNUSED_VARIABLE(input);
        UNUSED_VARIABLE(mode);
    }

    template <typename T>
    void computeTyped2(BufferView input, int mode) const {
        T* p = input.cast<T>();
        const size_t w = input.shape[0];
        const size_t h = input.shape[1];

        computeTyped2(p, w, h, mode);
    }

    template <typename T>
    void computeTyped3(BufferView input, int mode) const {
        UNUSED_VARIABLE(input);
        UNUSED_VARIABLE(mode);
    }
};

struct SolveLinearSystemOperator
    : public DimDispatcher<SolveLinearSystemOperator> {
    template <typename T>
    void computeTyped1(BufferView x, BufferView x0, BufferView buffer, T a, T c,
                       int bcMode) const {
        UNUSED_VARIABLE(x);
        UNUSED_VARIABLE(x0);
        UNUSED_VARIABLE(buffer);
        UNUSED_VARIABLE(a);
        UNUSED_VARIABLE(c);
        UNUSED_VARIABLE(bcMode);
    }

    template <typename T>
    void computeTyped2(BufferView x, BufferView x0, BufferView buffer, T a, T c,
                       int bcMode) const {
        T* xp = x.cast<T>();
        T* x0p = x0.cast<T>();
        T* bufferp = buffer.cast<T>();
        const size_t w = x.shape[0];
        const size_t h = x.shape[1];

        SetBoundaryConditionOperator setBndOp;

        for (int iter = 0; iter < 20; ++iter) {
            parallelRangeFor(
                kOneSize, w - 1, kOneSize, h - 1,
                [&](size_t iBegin, size_t iEnd, size_t jBegin, size_t jEnd) {
                    for (size_t j = jBegin; j < jEnd; ++j) {
                        for (size_t i = iBegin; i < iEnd; ++i) {
                            bufferp[I(i, j)] =
                                (x0p[I(i, j)] +
                                 a * (xp[I(i - 1, j)] + xp[I(i + 1, j)] +
                                      xp[I(i, j - 1)] + xp[I(i, j + 1)])) /
                                c;
                        }
                    }
                });

            setBndOp.computeTyped2(bufferp, w, h, bcMode);
            std::swap(bufferp, xp);
        }
    }

    template <typename T>
    void computeTyped3(BufferView x, BufferView x0, BufferView buffer, T a, T c,
                       int bcMode) const {
        UNUSED_VARIABLE(x);
        UNUSED_VARIABLE(x0);
        UNUSED_VARIABLE(buffer);
        UNUSED_VARIABLE(a);
        UNUSED_VARIABLE(c);
        UNUSED_VARIABLE(bcMode);
    }
};

void setBoundaryCondition(BufferView input, int mode) {
    SetBoundaryConditionOperator op;
    op.compute(input.dataType, input.ndim, input, mode);
}

void solveLinearSystem(BufferView x, BufferView x0, BufferView buffer, float a,
                       float c, int bcMode) {
    SolveLinearSystemOperator op;
    op.compute(x.dataType, x.ndim, x, x0, buffer, a, c, bcMode);
}

}  // namespace cpu

}  // namespace internal

}  // namespace core

}  // namespace jet
