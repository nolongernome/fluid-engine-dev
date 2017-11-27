// Copyright (c) 2017 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef SRC_JET_CORE_API_UTILS_H_
#define SRC_JET_CORE_API_UTILS_H_

#include <jet/core_api_buffer_view.h>

namespace jet {

namespace core {

namespace internal {

template <typename Subclass>
class TypeDispatcher {
 public:
    template <typename... Params>
    void compute(DataType dataType, Params... params) const {
        if (dataType == DataType::kInt8) {
            invokeComputeTyped<int8_t>(params...);
        } else if (dataType == DataType::kUInt8) {
            invokeComputeTyped<uint8_t>(params...);
        } else if (dataType == DataType::kInt16) {
            invokeComputeTyped<int16_t>(params...);
        } else if (dataType == DataType::kUInt16) {
            invokeComputeTyped<uint16_t>(params...);
        } else if (dataType == DataType::kInt32) {
            invokeComputeTyped<int32_t>(params...);
        } else if (dataType == DataType::kUInt32) {
            invokeComputeTyped<uint32_t>(params...);
        } else if (dataType == DataType::kInt64) {
            invokeComputeTyped<int64_t>(params...);
        } else if (dataType == DataType::kUInt64) {
            invokeComputeTyped<uint64_t>(params...);
        } else if (dataType == DataType::kFloat32) {
            invokeComputeTyped<float>(params...);
        } else if (dataType == DataType::kFloat64) {
            invokeComputeTyped<double>(params...);
        }
    }

 private:
    //! Returns actual implementation (the subclass).
    const Subclass &operator()() const {
        return static_cast<const Subclass &>(*this);
    }

    template <typename T, typename... Params>
    void invokeComputeTyped(Params... params) const {
        const auto &subc = (*this)();
        subc.template computeTyped<T>(params...);
    }
};

template <typename Subclass>
class DimDispatcher {
 public:
    template <typename... Params>
    void compute(DataType dataType, unsigned int ndim, Params... params) const {
        if (dataType == DataType::kInt8) {
            invokeComputeTyped<int8_t>(ndim, params...);
        } else if (dataType == DataType::kUInt8) {
            invokeComputeTyped<uint8_t>(ndim, params...);
        } else if (dataType == DataType::kInt16) {
            invokeComputeTyped<int16_t>(ndim, params...);
        } else if (dataType == DataType::kUInt16) {
            invokeComputeTyped<uint16_t>(ndim, params...);
        } else if (dataType == DataType::kInt32) {
            invokeComputeTyped<int32_t>(ndim, params...);
        } else if (dataType == DataType::kUInt32) {
            invokeComputeTyped<uint32_t>(ndim, params...);
        } else if (dataType == DataType::kInt64) {
            invokeComputeTyped<int64_t>(ndim, params...);
        } else if (dataType == DataType::kUInt64) {
            invokeComputeTyped<uint64_t>(ndim, params...);
        } else if (dataType == DataType::kFloat32) {
            invokeComputeTyped<float>(ndim, params...);
        } else if (dataType == DataType::kFloat64) {
            invokeComputeTyped<double>(ndim, params...);
        }
    }

 private:
    //! Returns actual implementation (the subclass).
    const Subclass &operator()() const {
        return static_cast<const Subclass &>(*this);
    }

    template <typename T, typename... Params>
    void invokeComputeTyped(unsigned int ndim, Params... params) const {
        const auto &subc = (*this)();
        if (ndim == 1) {
            subc.template computeTyped1<T>(params...);
        } else if (ndim == 2) {
            subc.template computeTyped2<T>(params...);
        } else if (ndim == 3) {
            subc.template computeTyped3<T>(params...);
        }
    }
};

}  // namespace internal

}  // namespace core

}  // namespace jet

#endif  // SRC_JET_CORE_API_UTILS_H_
