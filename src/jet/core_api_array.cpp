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

void copy(const BufferView& input, BufferView* output);
void add(const BufferView& a, const BufferView& b, BufferView* result);
void sub(const BufferView& a, const BufferView& b, BufferView* result);
void mul(const BufferView& a, const BufferView& b, BufferView* result);
void div(const BufferView& a, const BufferView& b, BufferView* result);
void axpy(const BufferView& a, const BufferView& x, const BufferView& y,
          BufferView* result);
void padEdge(BufferView* input,
             const std::array<std::array<size_t, 2>, 3>& padWidth);

}  // namespace cpu

namespace ispc {

void copy(const BufferView& input, BufferView* output);
void add(const BufferView& a, const BufferView& b, BufferView* result);
void sub(const BufferView& a, const BufferView& b, BufferView* result);
void mul(const BufferView& a, const BufferView& b, BufferView* result);
void div(const BufferView& a, const BufferView& b, BufferView* result);
void axpy(const BufferView& a, const BufferView& x, const BufferView& y,
          BufferView* result);
void padEdge(BufferView* input,
             const std::array<std::array<size_t, 2>, 3>& padWidth);

}  // namespace ispc

}  // namespace internal

void copy(const BufferView& input, BufferView* output) {
    // Check device
    JET_THROW_INVALID_ARG_IF(input.device != output->device);

    // Check size
    JET_THROW_INVALID_ARG_IF(input.length() != output->length());

    // Forward to device
    if (input.device == Device::kCpu) {
        internal::cpu::copy(input, output);
    } else if (input.device == Device::kIspc) {
        internal::ispc::copy(input, output);
    } else {
        JET_THROW_INVALID_ARG_WITH_MESSAGE_IF(
            true, "Unknown device for jet::core::copy");
    }
}

void add(const BufferView& a, const BufferView& b, BufferView* result) {
    // Check device
    JET_THROW_INVALID_ARG_IF(a.device != b.device ||
                             a.device != result->device);

    // Check size
    JET_THROW_INVALID_ARG_IF(a.length() != b.length() ||
                             a.length() != result->length());

    // Forward to device
    if (a.device == Device::kCpu) {
        internal::cpu::add(a, b, result);
    } else if (a.device == Device::kIspc) {
        internal::ispc::add(a, b, result);
    } else {
        JET_THROW_INVALID_ARG_WITH_MESSAGE_IF(
            true, "Unknown device for jet::core::add");
    }
}

void sub(const BufferView& a, const BufferView& b, BufferView* result) {
    // Check device
    JET_THROW_INVALID_ARG_IF(a.device != b.device ||
                             a.device != result->device);

    // Check size
    JET_THROW_INVALID_ARG_IF(a.length() != b.length() ||
                             a.length() != result->length());

    // Forward to device
    if (a.device == Device::kCpu) {
        internal::cpu::sub(a, b, result);
    } else if (a.device == Device::kIspc) {
        internal::ispc::sub(a, b, result);
    } else {
        JET_THROW_INVALID_ARG_WITH_MESSAGE_IF(
            true, "Unknown device for jet::core::sub");
    }
}

void mul(const BufferView& a, const BufferView& b, BufferView* result) {
    // Check device
    JET_THROW_INVALID_ARG_IF(a.device != b.device ||
                             a.device != result->device);

    // Check size
    JET_THROW_INVALID_ARG_IF(a.length() != b.length() ||
                             a.length() != result->length());

    // Forward to device
    if (a.device == Device::kCpu) {
        internal::cpu::mul(a, b, result);
    } else if (a.device == Device::kIspc) {
        internal::ispc::mul(a, b, result);
    } else {
        JET_THROW_INVALID_ARG_WITH_MESSAGE_IF(
            true, "Unknown device for jet::core::mul");
    }
}

void div(const BufferView& a, const BufferView& b, BufferView* result) {
    // Check device
    JET_THROW_INVALID_ARG_IF(a.device != b.device ||
                             a.device != result->device);

    // Check size
    JET_THROW_INVALID_ARG_IF(a.length() != b.length() ||
                             a.length() != result->length());

    // Forward to device
    if (a.device == Device::kCpu) {
        internal::cpu::div(a, b, result);
    } else if (a.device == Device::kIspc) {
        internal::ispc::div(a, b, result);
    } else {
        JET_THROW_INVALID_ARG_WITH_MESSAGE_IF(
            true, "Unknown device for jet::core::div");
    }
}

void axpy(const BufferView& a, const BufferView& x, const BufferView& y,
          BufferView* result) {
    // Check device
    JET_THROW_INVALID_ARG_IF(a.device != x.device || a.device != y.device ||
                             a.device != result->device);

    // Check size
    JET_THROW_INVALID_ARG_IF((a.length() != 1 && a.length() != x.length()) ||
                             x.length() != y.length() ||
                             x.length() != result->length());

    // Forward to device
    if (a.device == Device::kCpu) {
        internal::cpu::axpy(a, x, y, result);
    } else if (a.device == Device::kIspc) {
        internal::ispc::axpy(a, x, y, result);
    } else {
        JET_THROW_INVALID_ARG_WITH_MESSAGE_IF(
            true, "Unknown device for jet::core::axpy");
    }
}

void padEdge(BufferView* input,
             const std::array<std::array<size_t, 2>, 3>& padWidth) {
    // Check size
    for (unsigned int d = 0; d < input->ndim; ++d) {
        JET_THROW_INVALID_ARG_IF(input->shape[d] <=
                                 padWidth[d][0] + padWidth[d][1]);
    }

    // Forward to device
    if (input->device == Device::kCpu) {
        internal::cpu::padEdge(input, padWidth);
    } else if (input->device == Device::kIspc) {
        internal::ispc::padEdge(input, padWidth);
    } else {
        JET_THROW_INVALID_ARG_WITH_MESSAGE_IF(
            true, "Unknown device for jet::core::padEdge");
    }
}

}  // namespace core

}  // namespace jet
