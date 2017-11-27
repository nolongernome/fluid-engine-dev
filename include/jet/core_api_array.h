// Copyright (c) 2017 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef INCLUDE_JET_CORE_API_ARRAY_H_
#define INCLUDE_JET_CORE_API_ARRAY_H_

#include <jet/core_api_buffer_view.h>

#include <array>

namespace jet {

namespace core {

void copy(const BufferView& input, BufferView* output);

void add(const BufferView& a, const BufferView& b, BufferView* result);

void sub(const BufferView& a, const BufferView& b, BufferView* result);

void mul(const BufferView& a, const BufferView& b, BufferView* result);

void div(const BufferView& a, const BufferView& b, BufferView* result);

void axpy(const BufferView& a, const BufferView& x, const BufferView& y,
          BufferView* result);

void padEdge(BufferView* input,
             const std::array<std::array<size_t, 2>, 3>& padWidth);

}  // namespace core

}  // namespace jet

#endif  // INCLUDE_JET_CORE_API_ARRAY_H_
