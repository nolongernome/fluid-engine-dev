// Copyright (c) 2017 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <pch.h>

#include <jet/core_api_array.h>
namespace jet {

namespace core {

namespace internal {

namespace cpu {

void setBoundaryCondition(BufferView input, int mode);
void solveLinearSystem(BufferView x, BufferView x0, BufferView buffer, float a,
                       float c, int bcMode);

}  // namespace cpu

namespace ispc {

void setBoundaryCondition(BufferView input, int mode);

}  // namespace ispc

}  // namespace internal

void setBoundaryCondition(BufferView input, int mode) {
    // Check size
    JET_THROW_INVALID_ARG_IF(input.ndim < 2);
    for (unsigned int d = 0; d < input.ndim; ++d) {
        JET_THROW_INVALID_ARG_IF(input.shape[d] < 3);
    }

    // Check type
    JET_THROW_INVALID_ARG_IF(input.dataType != DataType::kFloat32 &&
                             input.dataType != DataType::kFloat64);

    // Forward to device
    if (input.device == Device::kCpu) {
        internal::cpu::setBoundaryCondition(input, mode);
    } else if (input.device == Device::kIspc) {
        internal::ispc::setBoundaryCondition(input, mode);
    } else {
        JET_THROW_INVALID_ARG_WITH_MESSAGE_IF(
            true, "Unknown device for jet::core::setBoundaryCondition");
    }
}

void solveLinearSystem(BufferView x, BufferView x0, BufferView buffer, float a,
                       float c, int bcMode) {
    // Check size
    JET_THROW_INVALID_ARG_IF(x.ndim < 2);
    for (unsigned int d = 0; d < x.ndim; ++d) {
        JET_THROW_INVALID_ARG_IF(x.shape[d] < 3);
        JET_THROW_INVALID_ARG_IF(x.shape[d] != x0.shape[d] &&
                                 x.shape[d] != buffer.shape[d]);
    }

    // Check type
    JET_THROW_INVALID_ARG_IF(x.dataType != DataType::kFloat32 &&
                             x.dataType != DataType::kFloat64);
    JET_THROW_INVALID_ARG_IF(x.dataType != x0.dataType &&
                             x.dataType != buffer.dataType);

    // Forward to device
    if (x.device == Device::kCpu) {
        internal::cpu::solveLinearSystem(x, x0, buffer, a, c, bcMode);
    } else if (x.device == Device::kIspc) {
    } else {
        JET_THROW_INVALID_ARG_WITH_MESSAGE_IF(
            true, "Unknown device for jet::core::setBoundaryCondition");
    }
}

}  // namespace core

}  // namespace jet
