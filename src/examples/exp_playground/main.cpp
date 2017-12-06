// Copyright (c) 2017 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <jet/jet.h>

using namespace jet;

enum class DataType : int8_t {
    kUnknown = 0,
    kInt8,
    kUInt8,
    kInt16,
    kUInt16,
    kInt32,
    kUInt32,
    kInt64,
    kUInt64,
    kFloat32,
    kFloat64,
};

enum class DeviceType : int {
    kCpu = 0,
    kCuda = 1,
    kMetal = 2,
};

template <typename T>
DataType getDataType() {
    return DataType::kUnknown;
}

template <>
constexpr DataType getDataType<int8_t>() {
    return DataType::kInt8;
}

template <>
constexpr DataType getDataType<uint8_t>() {
    return DataType::kUInt8;
}

template <>
constexpr DataType getDataType<int16_t>() {
    return DataType::kInt16;
}

template <>
constexpr DataType getDataType<uint16_t>() {
    return DataType::kUInt16;
}

template <>
constexpr DataType getDataType<int32_t>() {
    return DataType::kInt32;
}

template <>
constexpr DataType getDataType<uint32_t>() {
    return DataType::kUInt32;
}

template <>
constexpr DataType getDataType<int64_t>() {
    return DataType::kInt64;
}

template <>
constexpr DataType getDataType<uint64_t>() {
    return DataType::kUInt64;
}

template <>
constexpr DataType getDataType<float>() {
    return DataType::kFloat32;
}

template <>
constexpr DataType getDataType<double>() {
    return DataType::kFloat64;
}

size_t getDataTypeSize(DataType dataType) {
    switch (dataType) {
        case DataType::kInt8:
        case DataType::kUInt8:
            return 1;
        case DataType::kInt16:
        case DataType::kUInt16:
            return 2;
        case DataType::kInt32:
        case DataType::kUInt32:
        case DataType::kFloat32:
            return 4;
        case DataType::kInt64:
        case DataType::kUInt64:
        case DataType::kFloat64:
            return 8;
        default:
            return 0;
    }
}

class BufferView {
 public:
    BufferView() = default;

    BufferView(size_t numElem, DataType dataType, DeviceType deviceType) {
        set(numElem, dataType, deviceType);
    }

    virtual ~BufferView() = default;

    DataType dataType() const {
        return _dataType;
    }

    size_t numberOfElements() const {
        return _numElem;
    }

    size_t sizeInBytes() const {
        return _numElem * getDataTypeSize(_dataType);
    }

    DeviceType deviceType() const {
        return _deviceType;
    }

    void set(size_t numElem, DataType dataType, DeviceType deviceType) {
        _numElem = numElem;
        _dataType = dataType;
        _deviceType = deviceType;
    }

    void copyFromHost(void* data) {
        copyFromHost(data, _numElem);
    }

    void copyFromHost(void* data, size_t numElem) {
        copyFromHost(data, 0, numElem);
    }

    virtual void copyFromHost(void* data, size_t elemBegin, size_t elemEnd) = 0;

    virtual void copyToHost(void* data) {
        copyToHost(data, _numElem);
    }

    virtual void copyToHost(void* data, size_t numElem) {
        copyToHost(data, 0, numElem);
    }

    virtual void copyToHost(void* data, size_t elemBegin, size_t elemEnd) = 0;

 private:
    size_t _numElem = 0;
    DataType _dataType = DataType::kFloat32;
    DeviceType _deviceType = DeviceType::kCpu;
};

class HostBuffer;

class HostBufferView : public BufferView {
 public:
    HostBufferView() {
    }

    HostBufferView(void* data, size_t numElem, DataType dataType)
        : BufferView(numElem, dataType, DeviceType::kCpu) {
        _buffer = data;
    }

    HostBufferView(const HostBufferView& other)
        : HostBufferView(other._buffer, other.numberOfElements(),
                         other.dataType()) {
    }

    template <typename T, size_t N>
    explicit HostBufferView(const std::array<T, N>& other)
        : HostBufferView(other.data(), other.size(), getDataType<T>()) {
    }

    template <typename T>
    explicit HostBufferView(const std::vector<T>& other)
        : HostBufferView(other.data(), other.size(), getDataType<T>()) {
    }

    explicit HostBufferView(const HostBuffer& buffer);

    void copyFromHost(void* data, size_t elemBegin, size_t elemEnd) override {
        size_t size = getDataTypeSize(dataType());
        memcpy(_buffer, static_cast<int8_t*>(data) + size * elemBegin,
               size * (elemEnd - elemBegin));
    }

    void copyToHost(void* data, size_t elemBegin, size_t elemEnd) override {
        size_t size = getDataTypeSize(dataType());
        memcpy(data, static_cast<int8_t*>(_buffer) + size * elemBegin,
               size * (elemEnd - elemBegin));
    }

    void set(void* data, size_t numElem, DataType dataType) {
        _buffer = data;
        BufferView::set(numElem, dataType, DeviceType::kCpu);
    }

    template <typename T>
    T* data() {
        return static_cast<T*>(_buffer);
    }

    template <typename T>
    const T* data() const {
        return static_cast<const T*>(_buffer);
    }

 private:
    void* _buffer = nullptr;
};

class Buffer {
 public:
    Buffer() = default;
    virtual ~Buffer() = default;

    virtual DataType dataType() const = 0;

    virtual size_t numberOfElements() const = 0;

    virtual size_t sizeInBytes() const = 0;

    virtual DeviceType deviceType() const = 0;
};

class HostBuffer : public Buffer {
 public:
    HostBuffer() = default;

    HostBuffer(void* data, size_t numElem, DataType dataType) {
        size_t size = getDataTypeSize(dataType) * numElem;
        _buffer.resize(size);
        memcpy(_buffer.data(), data, size);
        _view.set(_buffer.data(), numElem, dataType);
    }

    HostBuffer(const HostBuffer& other) : _buffer(other._buffer) {
        _view.set(_buffer.data(), other.numberOfElements(), other.dataType());
    }

    template <typename T, size_t N>
    explicit HostBuffer(const std::array<T, N>& other)
        : HostBuffer(other.data(), other.size(), getDataType<T>()) {
    }

    template <typename T>
    explicit HostBuffer(const std::vector<T>& other)
        : HostBuffer(other.data(), other.size(), getDataType<T>()) {
    }

    DataType dataType() const override {
        return _view.dataType();
    }

    size_t numberOfElements() const override {
        return _view.numberOfElements();
    }

    size_t sizeInBytes() const override {
        return _view.sizeInBytes();
    }

    DeviceType deviceType() const override {
        return _view.deviceType();
    }

    HostBufferView& view() {
        return _view;
    }

    const HostBufferView& view() const {
        return _view;
    }

    template <typename T>
    T* data() {
        return _view.data<T>();
    }

    template <typename T>
    const T* data() const {
        return _view.data<T>();
    }

 private:
    std::vector<int8_t> _buffer;
    HostBufferView _view;
};

HostBufferView::HostBufferView(const HostBuffer& buffer) {
    *this = buffer.view();
}

class ParticleSystemData final {
 public:
    typedef size_t LayerId;

    ParticleSystemData();
    ParticleSystemData(size_t numberOfParticles);
    ParticleSystemData(const ParticleSystemData& other);
    ParticleSystemData(ParticleSystemData&& other);
    ~ParticleSystemData();

    void resize(size_t newNumberOfParticles);
    void clear();

    size_t numberOfParticles() const;
    bool isEmpty();
};

int main() {
    return 0;
}
