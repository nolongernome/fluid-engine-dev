// Copyright (c) 2017 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <pch.h>

#include <core_api_utils.h>

namespace jet {

namespace core {

namespace internal {

namespace ispc {

struct SetBoundaryConditionOperator
    : public DimDispatcher<SetBoundaryConditionOperator> {
    template <typename T>
    void computeTyped1(BufferView input, int mode) const {
        UNUSED_VARIABLE(input);
        UNUSED_VARIABLE(mode);
    }

    template <typename T>
    void computeTyped2(BufferView input, int mode) const {
        UNUSED_VARIABLE(input);
        UNUSED_VARIABLE(mode);
    }

    template <typename T>
    void computeTyped3(BufferView input, int mode) const {
        UNUSED_VARIABLE(input);
        UNUSED_VARIABLE(mode);
    }
};

void setBoundaryCondition(BufferView input, int mode) {
    SetBoundaryConditionOperator op;
    op.compute(input.dataType, input.ndim, input, mode);
}

}  // namespace ispc

}  // namespace internal

}  // namespace core

}  // namespace jet
