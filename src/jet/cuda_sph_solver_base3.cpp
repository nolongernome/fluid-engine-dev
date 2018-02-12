// Copyright (c) 2017 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifdef JET_USE_CUDA

#include <pch.h>

#include <jet/cuda_sph_solver_base3.h>

using namespace jet;
using namespace experimental;

CudaSphSolverBase3::CudaSphSolverBase3() {
    _sphSystemData = std::make_shared<CudaSphSystemData3>();
    _forcesIdx = _sphSystemData->addVectorData();
    _smoothedVelIdx = _sphSystemData->addVectorData();

    setIsUsingFixedSubTimeSteps(false);
}

CudaSphSolverBase3::~CudaSphSolverBase3() {}

float CudaSphSolverBase3::negativePressureScale() const {
    return _negativePressureScale;
}

void CudaSphSolverBase3::setNegativePressureScale(
    float newNegativePressureScale) {
    _negativePressureScale = newNegativePressureScale;
}

float CudaSphSolverBase3::viscosityCoefficient() const {
    return _viscosityCoefficient;
}

void CudaSphSolverBase3::setViscosityCoefficient(
    float newViscosityCoefficient) {
    _viscosityCoefficient = newViscosityCoefficient;
}

float CudaSphSolverBase3::pseudoViscosityCoefficient() const {
    return _pseudoViscosityCoefficient;
}

void CudaSphSolverBase3::setPseudoViscosityCoefficient(
    float newPseudoViscosityCoefficient) {
    _pseudoViscosityCoefficient = newPseudoViscosityCoefficient;
}

CudaSphSystemData3* CudaSphSolverBase3::sphSystemData() {
    return _sphSystemData.get();
}

const CudaSphSystemData3* CudaSphSolverBase3::sphSystemData() const {
    return _sphSystemData.get();
}

CudaArrayView1<float4> CudaSphSolverBase3::forces() const {
    return _sphSystemData->vectorDataAt(_forcesIdx);
}

CudaArrayView1<float4> CudaSphSolverBase3::smoothedVelocities() const {
    return _sphSystemData->vectorDataAt(_smoothedVelIdx);
}

#endif  // JET_USE_CUDA