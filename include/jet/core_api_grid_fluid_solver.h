// Copyright (c) 2017 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef INCLUDE_JET_CORE_API_GRID_FLUID_SOLVER_H_
#define INCLUDE_JET_CORE_API_GRID_FLUID_SOLVER_H_

#include <jet/core_api_buffer_view.h>

namespace jet {

namespace core {

void setBoundaryCondition(BufferView input, int mode);
void solveLinearSystem(BufferView x, BufferView x0, BufferView buffer, float a,
                       float c, int bcMode);

}  // namespace core

}  // namespace jet

#endif  // INCLUDE_JET_CORE_API_GRID_FLUID_SOLVER_H_
