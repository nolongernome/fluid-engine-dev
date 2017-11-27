// Copyright (c) 2017 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef INCLUDE_JET_CORE_API_DEVICE_H_
#define INCLUDE_JET_CORE_API_DEVICE_H_

#include <cstdlib>

namespace jet {

namespace core {

enum class Device : int {
    kCpu = 0,
    kIspc = 1,
    kCuda = 2,
};

}  // namespace core

}  // namespace jet

#endif  // INCLUDE_JET_CORE_API_DEVICE_H_
