// Copyright (c) 2017 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef INCLUDE_JET_CORE_API_BUFFER_VIEW_H_
#define INCLUDE_JET_CORE_API_BUFFER_VIEW_H_

#include <jet/core_api_device.h>

#include <array>
#include <vector>

namespace jet {

namespace core {

enum class DataType : int8_t {
    kInt8 = 0,
    kUInt8 = 1,
    kInt16 = 2,
    kUInt16 = 3,
    kInt32 = 4,
    kUInt32 = 5,
    kInt64 = 6,
    kUInt64 = 7,
    kFloat32 = 8,
    kFloat64 = 9,
};

// Similar to Python's buffer_info, but simplified.
// https://docs.python.org/2/c-api/buffer.html
struct BufferView {
    Device device = Device::kCpu;
    DataType dataType = DataType::kFloat32;
    unsigned int ndim = 1;
    void* buffer = nullptr;
    std::array<size_t, 3> shape{{1, 1, 1}};

    template <typename T>
    inline const T* cast() const {
        return static_cast<T*>(buffer);
    }

    template <typename T>
    inline T* cast() {
        return static_cast<T*>(buffer);
    }

    inline size_t length() const {
        if (ndim == 0) {
            return 0;
        }

        size_t aLen = 1;
        for (unsigned int i = 0; i < ndim; ++i) {
            aLen *= shape[i];
        }
        return aLen;
    }
};

class BufferViewBuilder {
 public:
    BufferViewBuilder& withView(const BufferView& bf) {
        _bf = bf;
        return *this;
    }

    BufferViewBuilder& withDevice(Device device) {
        _bf.device = device;
        return *this;
    }

    BufferViewBuilder& withDataType(DataType dtype) {
        _bf.dataType = dtype;
        return *this;
    }

    BufferViewBuilder& withBuffer(void* buffer) {
        _bf.buffer = buffer;
        return *this;
    }

    BufferViewBuilder& withShape(const std::vector<size_t>& shape) {
        _bf.shape = {{1, 1, 1}};
        for (size_t i = 0; i < shape.size(); ++i) {
            _bf.shape[i] = shape[i];
        }
        _bf.ndim = static_cast<unsigned int>(shape.size());
        return *this;
    }

    BufferView build() {
        BufferView bf;
        bf.device = _bf.device;
        bf.dataType = _bf.dataType;
        bf.ndim = _bf.ndim;
        bf.buffer = _bf.buffer;
        bf.shape = _bf.shape;
        return bf;
    }

 private:
    BufferView _bf;
};

}  // namespace core

}  // namespace jet

#endif  // INCLUDE_JET_CORE_API_BUFFER_VIEW_H_
