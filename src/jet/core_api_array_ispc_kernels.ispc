export void copyKernelS_int8_t(const uniform int8 a, uniform size_t n,
uniform int8 result[]) {
foreach (i = 0 ... n) { result[i] = a; }
}

export void copyKernelS_uint8_t(const uniform unsigned int8 a, uniform size_t n,
uniform unsigned int8 result[]) {
foreach (i = 0 ... n) { result[i] = a; }
}

export void copyKernelS_int16_t(const uniform int16 a, uniform size_t n,
uniform int16 result[]) {
foreach (i = 0 ... n) { result[i] = a; }
}

export void copyKernelS_uint16_t(const uniform unsigned int16 a, uniform size_t n,
uniform unsigned int16 result[]) {
foreach (i = 0 ... n) { result[i] = a; }
}

export void copyKernelS_int32_t(const uniform int32 a, uniform size_t n,
uniform int32 result[]) {
foreach (i = 0 ... n) { result[i] = a; }
}

export void copyKernelS_uint32_t(const uniform unsigned int32 a, uniform size_t n,
uniform unsigned int32 result[]) {
foreach (i = 0 ... n) { result[i] = a; }
}

export void copyKernelS_int64_t(const uniform int64 a, uniform size_t n,
uniform int64 result[]) {
foreach (i = 0 ... n) { result[i] = a; }
}

export void copyKernelS_uint64_t(const uniform unsigned int64 a, uniform size_t n,
uniform unsigned int64 result[]) {
foreach (i = 0 ... n) { result[i] = a; }
}

export void copyKernelS_float(const uniform float a, uniform size_t n,
uniform float result[]) {
foreach (i = 0 ... n) { result[i] = a; }
}

export void copyKernelS_double(const uniform double a, uniform size_t n,
uniform double result[]) {
foreach (i = 0 ... n) { result[i] = a; }
}

export void copyKernelV_int8_t(const uniform int8 a[], uniform size_t n,
uniform int8 result[]) {
foreach (i = 0 ... n) { result[i] = a[i]; }
}

export void copyKernelV_uint8_t(const uniform unsigned int8 a[], uniform size_t n,
uniform unsigned int8 result[]) {
foreach (i = 0 ... n) { result[i] = a[i]; }
}

export void copyKernelV_int16_t(const uniform int16 a[], uniform size_t n,
uniform int16 result[]) {
foreach (i = 0 ... n) { result[i] = a[i]; }
}

export void copyKernelV_uint16_t(const uniform unsigned int16 a[], uniform size_t n,
uniform unsigned int16 result[]) {
foreach (i = 0 ... n) { result[i] = a[i]; }
}

export void copyKernelV_int32_t(const uniform int32 a[], uniform size_t n,
uniform int32 result[]) {
foreach (i = 0 ... n) { result[i] = a[i]; }
}

export void copyKernelV_uint32_t(const uniform unsigned int32 a[], uniform size_t n,
uniform unsigned int32 result[]) {
foreach (i = 0 ... n) { result[i] = a[i]; }
}

export void copyKernelV_int64_t(const uniform int64 a[], uniform size_t n,
uniform int64 result[]) {
foreach (i = 0 ... n) { result[i] = a[i]; }
}

export void copyKernelV_uint64_t(const uniform unsigned int64 a[], uniform size_t n,
uniform unsigned int64 result[]) {
foreach (i = 0 ... n) { result[i] = a[i]; }
}

export void copyKernelV_float(const uniform float a[], uniform size_t n,
uniform float result[]) {
foreach (i = 0 ... n) { result[i] = a[i]; }
}

export void copyKernelV_double(const uniform double a[], uniform size_t n,
uniform double result[]) {
foreach (i = 0 ... n) { result[i] = a[i]; }
}

export void addKernelS_int8_t(const uniform int8 a, const uniform int8 b[],
uniform size_t n, uniform int8 result[]) {
foreach (i = 0 ... n) { result[i] = a + b[i]; }
}

export void addKernelS_uint8_t(const uniform unsigned int8 a, const uniform unsigned int8 b[],
uniform size_t n, uniform unsigned int8 result[]) {
foreach (i = 0 ... n) { result[i] = a + b[i]; }
}

export void addKernelS_int16_t(const uniform int16 a, const uniform int16 b[],
uniform size_t n, uniform int16 result[]) {
foreach (i = 0 ... n) { result[i] = a + b[i]; }
}

export void addKernelS_uint16_t(const uniform unsigned int16 a, const uniform unsigned int16 b[],
uniform size_t n, uniform unsigned int16 result[]) {
foreach (i = 0 ... n) { result[i] = a + b[i]; }
}

export void addKernelS_int32_t(const uniform int32 a, const uniform int32 b[],
uniform size_t n, uniform int32 result[]) {
foreach (i = 0 ... n) { result[i] = a + b[i]; }
}

export void addKernelS_uint32_t(const uniform unsigned int32 a, const uniform unsigned int32 b[],
uniform size_t n, uniform unsigned int32 result[]) {
foreach (i = 0 ... n) { result[i] = a + b[i]; }
}

export void addKernelS_int64_t(const uniform int64 a, const uniform int64 b[],
uniform size_t n, uniform int64 result[]) {
foreach (i = 0 ... n) { result[i] = a + b[i]; }
}

export void addKernelS_uint64_t(const uniform unsigned int64 a, const uniform unsigned int64 b[],
uniform size_t n, uniform unsigned int64 result[]) {
foreach (i = 0 ... n) { result[i] = a + b[i]; }
}

export void addKernelS_float(const uniform float a, const uniform float b[],
uniform size_t n, uniform float result[]) {
foreach (i = 0 ... n) { result[i] = a + b[i]; }
}

export void addKernelS_double(const uniform double a, const uniform double b[],
uniform size_t n, uniform double result[]) {
foreach (i = 0 ... n) { result[i] = a + b[i]; }
}

export void addKernelV_int8_t(const uniform int8 a[], const uniform int8 b[],
uniform size_t n, uniform int8 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] + b[i]; }
}

export void addKernelV_uint8_t(const uniform unsigned int8 a[], const uniform unsigned int8 b[],
uniform size_t n, uniform unsigned int8 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] + b[i]; }
}

export void addKernelV_int16_t(const uniform int16 a[], const uniform int16 b[],
uniform size_t n, uniform int16 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] + b[i]; }
}

export void addKernelV_uint16_t(const uniform unsigned int16 a[], const uniform unsigned int16 b[],
uniform size_t n, uniform unsigned int16 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] + b[i]; }
}

export void addKernelV_int32_t(const uniform int32 a[], const uniform int32 b[],
uniform size_t n, uniform int32 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] + b[i]; }
}

export void addKernelV_uint32_t(const uniform unsigned int32 a[], const uniform unsigned int32 b[],
uniform size_t n, uniform unsigned int32 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] + b[i]; }
}

export void addKernelV_int64_t(const uniform int64 a[], const uniform int64 b[],
uniform size_t n, uniform int64 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] + b[i]; }
}

export void addKernelV_uint64_t(const uniform unsigned int64 a[], const uniform unsigned int64 b[],
uniform size_t n, uniform unsigned int64 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] + b[i]; }
}

export void addKernelV_float(const uniform float a[], const uniform float b[],
uniform size_t n, uniform float result[]) {
foreach (i = 0 ... n) { result[i] = a[i] + b[i]; }
}

export void addKernelV_double(const uniform double a[], const uniform double b[],
uniform size_t n, uniform double result[]) {
foreach (i = 0 ... n) { result[i] = a[i] + b[i]; }
}

export void subKernelS_int8_t(const uniform int8 a, const uniform int8 b[],
uniform size_t n, uniform int8 result[]) {
foreach (i = 0 ... n) { result[i] = a - b[i]; }
}

export void subKernelS_uint8_t(const uniform unsigned int8 a, const uniform unsigned int8 b[],
uniform size_t n, uniform unsigned int8 result[]) {
foreach (i = 0 ... n) { result[i] = a - b[i]; }
}

export void subKernelS_int16_t(const uniform int16 a, const uniform int16 b[],
uniform size_t n, uniform int16 result[]) {
foreach (i = 0 ... n) { result[i] = a - b[i]; }
}

export void subKernelS_uint16_t(const uniform unsigned int16 a, const uniform unsigned int16 b[],
uniform size_t n, uniform unsigned int16 result[]) {
foreach (i = 0 ... n) { result[i] = a - b[i]; }
}

export void subKernelS_int32_t(const uniform int32 a, const uniform int32 b[],
uniform size_t n, uniform int32 result[]) {
foreach (i = 0 ... n) { result[i] = a - b[i]; }
}

export void subKernelS_uint32_t(const uniform unsigned int32 a, const uniform unsigned int32 b[],
uniform size_t n, uniform unsigned int32 result[]) {
foreach (i = 0 ... n) { result[i] = a - b[i]; }
}

export void subKernelS_int64_t(const uniform int64 a, const uniform int64 b[],
uniform size_t n, uniform int64 result[]) {
foreach (i = 0 ... n) { result[i] = a - b[i]; }
}

export void subKernelS_uint64_t(const uniform unsigned int64 a, const uniform unsigned int64 b[],
uniform size_t n, uniform unsigned int64 result[]) {
foreach (i = 0 ... n) { result[i] = a - b[i]; }
}

export void subKernelS_float(const uniform float a, const uniform float b[],
uniform size_t n, uniform float result[]) {
foreach (i = 0 ... n) { result[i] = a - b[i]; }
}

export void subKernelS_double(const uniform double a, const uniform double b[],
uniform size_t n, uniform double result[]) {
foreach (i = 0 ... n) { result[i] = a - b[i]; }
}

export void subKernelV_int8_t(const uniform int8 a[], const uniform int8 b[],
uniform size_t n, uniform int8 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] - b[i]; }
}

export void subKernelV_uint8_t(const uniform unsigned int8 a[], const uniform unsigned int8 b[],
uniform size_t n, uniform unsigned int8 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] - b[i]; }
}

export void subKernelV_int16_t(const uniform int16 a[], const uniform int16 b[],
uniform size_t n, uniform int16 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] - b[i]; }
}

export void subKernelV_uint16_t(const uniform unsigned int16 a[], const uniform unsigned int16 b[],
uniform size_t n, uniform unsigned int16 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] - b[i]; }
}

export void subKernelV_int32_t(const uniform int32 a[], const uniform int32 b[],
uniform size_t n, uniform int32 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] - b[i]; }
}

export void subKernelV_uint32_t(const uniform unsigned int32 a[], const uniform unsigned int32 b[],
uniform size_t n, uniform unsigned int32 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] - b[i]; }
}

export void subKernelV_int64_t(const uniform int64 a[], const uniform int64 b[],
uniform size_t n, uniform int64 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] - b[i]; }
}

export void subKernelV_uint64_t(const uniform unsigned int64 a[], const uniform unsigned int64 b[],
uniform size_t n, uniform unsigned int64 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] - b[i]; }
}

export void subKernelV_float(const uniform float a[], const uniform float b[],
uniform size_t n, uniform float result[]) {
foreach (i = 0 ... n) { result[i] = a[i] - b[i]; }
}

export void subKernelV_double(const uniform double a[], const uniform double b[],
uniform size_t n, uniform double result[]) {
foreach (i = 0 ... n) { result[i] = a[i] - b[i]; }
}

export void mulKernelS_int8_t(const uniform int8 a, const uniform int8 b[],
uniform size_t n, uniform int8 result[]) {
foreach (i = 0 ... n) { result[i] = a * b[i]; }
}

export void mulKernelS_uint8_t(const uniform unsigned int8 a, const uniform unsigned int8 b[],
uniform size_t n, uniform unsigned int8 result[]) {
foreach (i = 0 ... n) { result[i] = a * b[i]; }
}

export void mulKernelS_int16_t(const uniform int16 a, const uniform int16 b[],
uniform size_t n, uniform int16 result[]) {
foreach (i = 0 ... n) { result[i] = a * b[i]; }
}

export void mulKernelS_uint16_t(const uniform unsigned int16 a, const uniform unsigned int16 b[],
uniform size_t n, uniform unsigned int16 result[]) {
foreach (i = 0 ... n) { result[i] = a * b[i]; }
}

export void mulKernelS_int32_t(const uniform int32 a, const uniform int32 b[],
uniform size_t n, uniform int32 result[]) {
foreach (i = 0 ... n) { result[i] = a * b[i]; }
}

export void mulKernelS_uint32_t(const uniform unsigned int32 a, const uniform unsigned int32 b[],
uniform size_t n, uniform unsigned int32 result[]) {
foreach (i = 0 ... n) { result[i] = a * b[i]; }
}

export void mulKernelS_int64_t(const uniform int64 a, const uniform int64 b[],
uniform size_t n, uniform int64 result[]) {
foreach (i = 0 ... n) { result[i] = a * b[i]; }
}

export void mulKernelS_uint64_t(const uniform unsigned int64 a, const uniform unsigned int64 b[],
uniform size_t n, uniform unsigned int64 result[]) {
foreach (i = 0 ... n) { result[i] = a * b[i]; }
}

export void mulKernelS_float(const uniform float a, const uniform float b[],
uniform size_t n, uniform float result[]) {
foreach (i = 0 ... n) { result[i] = a * b[i]; }
}

export void mulKernelS_double(const uniform double a, const uniform double b[],
uniform size_t n, uniform double result[]) {
foreach (i = 0 ... n) { result[i] = a * b[i]; }
}

export void mulKernelV_int8_t(const uniform int8 a[], const uniform int8 b[],
uniform size_t n, uniform int8 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] * b[i]; }
}

export void mulKernelV_uint8_t(const uniform unsigned int8 a[], const uniform unsigned int8 b[],
uniform size_t n, uniform unsigned int8 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] * b[i]; }
}

export void mulKernelV_int16_t(const uniform int16 a[], const uniform int16 b[],
uniform size_t n, uniform int16 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] * b[i]; }
}

export void mulKernelV_uint16_t(const uniform unsigned int16 a[], const uniform unsigned int16 b[],
uniform size_t n, uniform unsigned int16 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] * b[i]; }
}

export void mulKernelV_int32_t(const uniform int32 a[], const uniform int32 b[],
uniform size_t n, uniform int32 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] * b[i]; }
}

export void mulKernelV_uint32_t(const uniform unsigned int32 a[], const uniform unsigned int32 b[],
uniform size_t n, uniform unsigned int32 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] * b[i]; }
}

export void mulKernelV_int64_t(const uniform int64 a[], const uniform int64 b[],
uniform size_t n, uniform int64 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] * b[i]; }
}

export void mulKernelV_uint64_t(const uniform unsigned int64 a[], const uniform unsigned int64 b[],
uniform size_t n, uniform unsigned int64 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] * b[i]; }
}

export void mulKernelV_float(const uniform float a[], const uniform float b[],
uniform size_t n, uniform float result[]) {
foreach (i = 0 ... n) { result[i] = a[i] * b[i]; }
}

export void mulKernelV_double(const uniform double a[], const uniform double b[],
uniform size_t n, uniform double result[]) {
foreach (i = 0 ... n) { result[i] = a[i] * b[i]; }
}

export void divKernelS_int8_t(const uniform int8 a, const uniform int8 b[],
uniform size_t n, uniform int8 result[]) {
foreach (i = 0 ... n) { result[i] = a / b[i]; }
}

export void divKernelS_uint8_t(const uniform unsigned int8 a, const uniform unsigned int8 b[],
uniform size_t n, uniform unsigned int8 result[]) {
foreach (i = 0 ... n) { result[i] = a / b[i]; }
}

export void divKernelS_int16_t(const uniform int16 a, const uniform int16 b[],
uniform size_t n, uniform int16 result[]) {
foreach (i = 0 ... n) { result[i] = a / b[i]; }
}

export void divKernelS_uint16_t(const uniform unsigned int16 a, const uniform unsigned int16 b[],
uniform size_t n, uniform unsigned int16 result[]) {
foreach (i = 0 ... n) { result[i] = a / b[i]; }
}

export void divKernelS_int32_t(const uniform int32 a, const uniform int32 b[],
uniform size_t n, uniform int32 result[]) {
foreach (i = 0 ... n) { result[i] = a / b[i]; }
}

export void divKernelS_uint32_t(const uniform unsigned int32 a, const uniform unsigned int32 b[],
uniform size_t n, uniform unsigned int32 result[]) {
foreach (i = 0 ... n) { result[i] = a / b[i]; }
}

export void divKernelS_int64_t(const uniform int64 a, const uniform int64 b[],
uniform size_t n, uniform int64 result[]) {
foreach (i = 0 ... n) { result[i] = a / b[i]; }
}

export void divKernelS_uint64_t(const uniform unsigned int64 a, const uniform unsigned int64 b[],
uniform size_t n, uniform unsigned int64 result[]) {
foreach (i = 0 ... n) { result[i] = a / b[i]; }
}

export void divKernelS_float(const uniform float a, const uniform float b[],
uniform size_t n, uniform float result[]) {
foreach (i = 0 ... n) { result[i] = a / b[i]; }
}

export void divKernelS_double(const uniform double a, const uniform double b[],
uniform size_t n, uniform double result[]) {
foreach (i = 0 ... n) { result[i] = a / b[i]; }
}

export void divKernelV_int8_t(const uniform int8 a[], const uniform int8 b[],
uniform size_t n, uniform int8 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] / b[i]; }
}

export void divKernelV_uint8_t(const uniform unsigned int8 a[], const uniform unsigned int8 b[],
uniform size_t n, uniform unsigned int8 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] / b[i]; }
}

export void divKernelV_int16_t(const uniform int16 a[], const uniform int16 b[],
uniform size_t n, uniform int16 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] / b[i]; }
}

export void divKernelV_uint16_t(const uniform unsigned int16 a[], const uniform unsigned int16 b[],
uniform size_t n, uniform unsigned int16 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] / b[i]; }
}

export void divKernelV_int32_t(const uniform int32 a[], const uniform int32 b[],
uniform size_t n, uniform int32 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] / b[i]; }
}

export void divKernelV_uint32_t(const uniform unsigned int32 a[], const uniform unsigned int32 b[],
uniform size_t n, uniform unsigned int32 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] / b[i]; }
}

export void divKernelV_int64_t(const uniform int64 a[], const uniform int64 b[],
uniform size_t n, uniform int64 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] / b[i]; }
}

export void divKernelV_uint64_t(const uniform unsigned int64 a[], const uniform unsigned int64 b[],
uniform size_t n, uniform unsigned int64 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] / b[i]; }
}

export void divKernelV_float(const uniform float a[], const uniform float b[],
uniform size_t n, uniform float result[]) {
foreach (i = 0 ... n) { result[i] = a[i] / b[i]; }
}

export void divKernelV_double(const uniform double a[], const uniform double b[],
uniform size_t n, uniform double result[]) {
foreach (i = 0 ... n) { result[i] = a[i] / b[i]; }
}

export void axpyKernelS_int8_t(uniform int8 a, const uniform int8 x[],
const uniform int8 y[], uniform size_t n,
uniform int8 result[]) {
foreach (i = 0 ... n) { result[i] = a * x[i] + y[i]; }
}

export void axpyKernelS_uint8_t(uniform unsigned int8 a, const uniform unsigned int8 x[],
const uniform unsigned int8 y[], uniform size_t n,
uniform unsigned int8 result[]) {
foreach (i = 0 ... n) { result[i] = a * x[i] + y[i]; }
}

export void axpyKernelS_int16_t(uniform int16 a, const uniform int16 x[],
const uniform int16 y[], uniform size_t n,
uniform int16 result[]) {
foreach (i = 0 ... n) { result[i] = a * x[i] + y[i]; }
}

export void axpyKernelS_uint16_t(uniform unsigned int16 a, const uniform unsigned int16 x[],
const uniform unsigned int16 y[], uniform size_t n,
uniform unsigned int16 result[]) {
foreach (i = 0 ... n) { result[i] = a * x[i] + y[i]; }
}

export void axpyKernelS_int32_t(uniform int32 a, const uniform int32 x[],
const uniform int32 y[], uniform size_t n,
uniform int32 result[]) {
foreach (i = 0 ... n) { result[i] = a * x[i] + y[i]; }
}

export void axpyKernelS_uint32_t(uniform unsigned int32 a, const uniform unsigned int32 x[],
const uniform unsigned int32 y[], uniform size_t n,
uniform unsigned int32 result[]) {
foreach (i = 0 ... n) { result[i] = a * x[i] + y[i]; }
}

export void axpyKernelS_int64_t(uniform int64 a, const uniform int64 x[],
const uniform int64 y[], uniform size_t n,
uniform int64 result[]) {
foreach (i = 0 ... n) { result[i] = a * x[i] + y[i]; }
}

export void axpyKernelS_uint64_t(uniform unsigned int64 a, const uniform unsigned int64 x[],
const uniform unsigned int64 y[], uniform size_t n,
uniform unsigned int64 result[]) {
foreach (i = 0 ... n) { result[i] = a * x[i] + y[i]; }
}

export void axpyKernelS_float(uniform float a, const uniform float x[],
const uniform float y[], uniform size_t n,
uniform float result[]) {
foreach (i = 0 ... n) { result[i] = a * x[i] + y[i]; }
}

export void axpyKernelS_double(uniform double a, const uniform double x[],
const uniform double y[], uniform size_t n,
uniform double result[]) {
foreach (i = 0 ... n) { result[i] = a * x[i] + y[i]; }
}

export void axpyKernelV_int8_t(const uniform int8 a[], const uniform int8 x[],
const uniform int8 y[], uniform size_t n,
uniform int8 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] * x[i] + y[i]; }
}

export void axpyKernelV_uint8_t(const uniform unsigned int8 a[], const uniform unsigned int8 x[],
const uniform unsigned int8 y[], uniform size_t n,
uniform unsigned int8 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] * x[i] + y[i]; }
}

export void axpyKernelV_int16_t(const uniform int16 a[], const uniform int16 x[],
const uniform int16 y[], uniform size_t n,
uniform int16 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] * x[i] + y[i]; }
}

export void axpyKernelV_uint16_t(const uniform unsigned int16 a[], const uniform unsigned int16 x[],
const uniform unsigned int16 y[], uniform size_t n,
uniform unsigned int16 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] * x[i] + y[i]; }
}

export void axpyKernelV_int32_t(const uniform int32 a[], const uniform int32 x[],
const uniform int32 y[], uniform size_t n,
uniform int32 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] * x[i] + y[i]; }
}

export void axpyKernelV_uint32_t(const uniform unsigned int32 a[], const uniform unsigned int32 x[],
const uniform unsigned int32 y[], uniform size_t n,
uniform unsigned int32 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] * x[i] + y[i]; }
}

export void axpyKernelV_int64_t(const uniform int64 a[], const uniform int64 x[],
const uniform int64 y[], uniform size_t n,
uniform int64 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] * x[i] + y[i]; }
}

export void axpyKernelV_uint64_t(const uniform unsigned int64 a[], const uniform unsigned int64 x[],
const uniform unsigned int64 y[], uniform size_t n,
uniform unsigned int64 result[]) {
foreach (i = 0 ... n) { result[i] = a[i] * x[i] + y[i]; }
}

export void axpyKernelV_float(const uniform float a[], const uniform float x[],
const uniform float y[], uniform size_t n,
uniform float result[]) {
foreach (i = 0 ... n) { result[i] = a[i] * x[i] + y[i]; }
}

export void axpyKernelV_double(const uniform double a[], const uniform double x[],
const uniform double y[], uniform size_t n,
uniform double result[]) {
foreach (i = 0 ... n) { result[i] = a[i] * x[i] + y[i]; }
}

export void padEdge1_int8_t(uniform int8 p[], uniform size_t n,
uniform size_t padLeft, uniform size_t padRight) {
int8 valLeft = p[padLeft];
foreach (i = 0 ... padLeft) { p[i] = valLeft; }

int8 valRight = p[n - padRight - 1];
foreach (i = n - padRight - 1 ... n) { p[i] = valRight; }
}

export void padEdge1_uint8_t(uniform unsigned int8 p[], uniform size_t n,
uniform size_t padLeft, uniform size_t padRight) {
unsigned int8 valLeft = p[padLeft];
foreach (i = 0 ... padLeft) { p[i] = valLeft; }

unsigned int8 valRight = p[n - padRight - 1];
foreach (i = n - padRight - 1 ... n) { p[i] = valRight; }
}

export void padEdge1_int16_t(uniform int16 p[], uniform size_t n,
uniform size_t padLeft, uniform size_t padRight) {
int16 valLeft = p[padLeft];
foreach (i = 0 ... padLeft) { p[i] = valLeft; }

int16 valRight = p[n - padRight - 1];
foreach (i = n - padRight - 1 ... n) { p[i] = valRight; }
}

export void padEdge1_uint16_t(uniform unsigned int16 p[], uniform size_t n,
uniform size_t padLeft, uniform size_t padRight) {
unsigned int16 valLeft = p[padLeft];
foreach (i = 0 ... padLeft) { p[i] = valLeft; }

unsigned int16 valRight = p[n - padRight - 1];
foreach (i = n - padRight - 1 ... n) { p[i] = valRight; }
}

export void padEdge1_int32_t(uniform int32 p[], uniform size_t n,
uniform size_t padLeft, uniform size_t padRight) {
int32 valLeft = p[padLeft];
foreach (i = 0 ... padLeft) { p[i] = valLeft; }

int32 valRight = p[n - padRight - 1];
foreach (i = n - padRight - 1 ... n) { p[i] = valRight; }
}

export void padEdge1_uint32_t(uniform unsigned int32 p[], uniform size_t n,
uniform size_t padLeft, uniform size_t padRight) {
unsigned int32 valLeft = p[padLeft];
foreach (i = 0 ... padLeft) { p[i] = valLeft; }

unsigned int32 valRight = p[n - padRight - 1];
foreach (i = n - padRight - 1 ... n) { p[i] = valRight; }
}

export void padEdge1_int64_t(uniform int64 p[], uniform size_t n,
uniform size_t padLeft, uniform size_t padRight) {
int64 valLeft = p[padLeft];
foreach (i = 0 ... padLeft) { p[i] = valLeft; }

int64 valRight = p[n - padRight - 1];
foreach (i = n - padRight - 1 ... n) { p[i] = valRight; }
}

export void padEdge1_uint64_t(uniform unsigned int64 p[], uniform size_t n,
uniform size_t padLeft, uniform size_t padRight) {
unsigned int64 valLeft = p[padLeft];
foreach (i = 0 ... padLeft) { p[i] = valLeft; }

unsigned int64 valRight = p[n - padRight - 1];
foreach (i = n - padRight - 1 ... n) { p[i] = valRight; }
}

export void padEdge1_float(uniform float p[], uniform size_t n,
uniform size_t padLeft, uniform size_t padRight) {
float valLeft = p[padLeft];
foreach (i = 0 ... padLeft) { p[i] = valLeft; }

float valRight = p[n - padRight - 1];
foreach (i = n - padRight - 1 ... n) { p[i] = valRight; }
}

export void padEdge1_double(uniform double p[], uniform size_t n,
uniform size_t padLeft, uniform size_t padRight) {
double valLeft = p[padLeft];
foreach (i = 0 ... padLeft) { p[i] = valLeft; }

double valRight = p[n - padRight - 1];
foreach (i = n - padRight - 1 ... n) { p[i] = valRight; }
}

export void padEdge2_int8_t(uniform int8 p[], uniform size_t w, uniform size_t h,
uniform size_t padLeft, uniform size_t padRight,
uniform size_t padBottom, uniform size_t padTop) {
// i
foreach (j = padBottom... h - padTop) {
int8* row = p + j * w;

const int8 valLeft = row[padLeft];
for (size_t i = 0; i < padLeft; ++i) {
row[i] = valLeft;
}

const int8 valRight = row[w - padRight - 1];
for (size_t i = w - padRight; i < w; ++i) {
row[i] = valRight;
}
}

// j
const int8* rowBottom = p + padBottom * w;
foreach (j = 0 ... padBottom) {
int8* row = p + j * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBottom[i];
}
}

const int8* rowTop = p + (padTop - 1) * w;
foreach (j = padTop... h - padTop) {
int8* row = p + j * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowTop[i];
}
}
}

export void padEdge2_uint8_t(uniform unsigned int8 p[], uniform size_t w, uniform size_t h,
uniform size_t padLeft, uniform size_t padRight,
uniform size_t padBottom, uniform size_t padTop) {
// i
foreach (j = padBottom... h - padTop) {
unsigned int8* row = p + j * w;

const unsigned int8 valLeft = row[padLeft];
for (size_t i = 0; i < padLeft; ++i) {
row[i] = valLeft;
}

const unsigned int8 valRight = row[w - padRight - 1];
for (size_t i = w - padRight; i < w; ++i) {
row[i] = valRight;
}
}

// j
const unsigned int8* rowBottom = p + padBottom * w;
foreach (j = 0 ... padBottom) {
unsigned int8* row = p + j * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBottom[i];
}
}

const unsigned int8* rowTop = p + (padTop - 1) * w;
foreach (j = padTop... h - padTop) {
unsigned int8* row = p + j * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowTop[i];
}
}
}

export void padEdge2_int16_t(uniform int16 p[], uniform size_t w, uniform size_t h,
uniform size_t padLeft, uniform size_t padRight,
uniform size_t padBottom, uniform size_t padTop) {
// i
foreach (j = padBottom... h - padTop) {
int16* row = p + j * w;

const int16 valLeft = row[padLeft];
for (size_t i = 0; i < padLeft; ++i) {
row[i] = valLeft;
}

const int16 valRight = row[w - padRight - 1];
for (size_t i = w - padRight; i < w; ++i) {
row[i] = valRight;
}
}

// j
const int16* rowBottom = p + padBottom * w;
foreach (j = 0 ... padBottom) {
int16* row = p + j * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBottom[i];
}
}

const int16* rowTop = p + (padTop - 1) * w;
foreach (j = padTop... h - padTop) {
int16* row = p + j * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowTop[i];
}
}
}

export void padEdge2_uint16_t(uniform unsigned int16 p[], uniform size_t w, uniform size_t h,
uniform size_t padLeft, uniform size_t padRight,
uniform size_t padBottom, uniform size_t padTop) {
// i
foreach (j = padBottom... h - padTop) {
unsigned int16* row = p + j * w;

const unsigned int16 valLeft = row[padLeft];
for (size_t i = 0; i < padLeft; ++i) {
row[i] = valLeft;
}

const unsigned int16 valRight = row[w - padRight - 1];
for (size_t i = w - padRight; i < w; ++i) {
row[i] = valRight;
}
}

// j
const unsigned int16* rowBottom = p + padBottom * w;
foreach (j = 0 ... padBottom) {
unsigned int16* row = p + j * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBottom[i];
}
}

const unsigned int16* rowTop = p + (padTop - 1) * w;
foreach (j = padTop... h - padTop) {
unsigned int16* row = p + j * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowTop[i];
}
}
}

export void padEdge2_int32_t(uniform int32 p[], uniform size_t w, uniform size_t h,
uniform size_t padLeft, uniform size_t padRight,
uniform size_t padBottom, uniform size_t padTop) {
// i
foreach (j = padBottom... h - padTop) {
int32* row = p + j * w;

const int32 valLeft = row[padLeft];
for (size_t i = 0; i < padLeft; ++i) {
row[i] = valLeft;
}

const int32 valRight = row[w - padRight - 1];
for (size_t i = w - padRight; i < w; ++i) {
row[i] = valRight;
}
}

// j
const int32* rowBottom = p + padBottom * w;
foreach (j = 0 ... padBottom) {
int32* row = p + j * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBottom[i];
}
}

const int32* rowTop = p + (padTop - 1) * w;
foreach (j = padTop... h - padTop) {
int32* row = p + j * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowTop[i];
}
}
}

export void padEdge2_uint32_t(uniform unsigned int32 p[], uniform size_t w, uniform size_t h,
uniform size_t padLeft, uniform size_t padRight,
uniform size_t padBottom, uniform size_t padTop) {
// i
foreach (j = padBottom... h - padTop) {
unsigned int32* row = p + j * w;

const unsigned int32 valLeft = row[padLeft];
for (size_t i = 0; i < padLeft; ++i) {
row[i] = valLeft;
}

const unsigned int32 valRight = row[w - padRight - 1];
for (size_t i = w - padRight; i < w; ++i) {
row[i] = valRight;
}
}

// j
const unsigned int32* rowBottom = p + padBottom * w;
foreach (j = 0 ... padBottom) {
unsigned int32* row = p + j * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBottom[i];
}
}

const unsigned int32* rowTop = p + (padTop - 1) * w;
foreach (j = padTop... h - padTop) {
unsigned int32* row = p + j * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowTop[i];
}
}
}

export void padEdge2_int64_t(uniform int64 p[], uniform size_t w, uniform size_t h,
uniform size_t padLeft, uniform size_t padRight,
uniform size_t padBottom, uniform size_t padTop) {
// i
foreach (j = padBottom... h - padTop) {
int64* row = p + j * w;

const int64 valLeft = row[padLeft];
for (size_t i = 0; i < padLeft; ++i) {
row[i] = valLeft;
}

const int64 valRight = row[w - padRight - 1];
for (size_t i = w - padRight; i < w; ++i) {
row[i] = valRight;
}
}

// j
const int64* rowBottom = p + padBottom * w;
foreach (j = 0 ... padBottom) {
int64* row = p + j * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBottom[i];
}
}

const int64* rowTop = p + (padTop - 1) * w;
foreach (j = padTop... h - padTop) {
int64* row = p + j * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowTop[i];
}
}
}

export void padEdge2_uint64_t(uniform unsigned int64 p[], uniform size_t w, uniform size_t h,
uniform size_t padLeft, uniform size_t padRight,
uniform size_t padBottom, uniform size_t padTop) {
// i
foreach (j = padBottom... h - padTop) {
unsigned int64* row = p + j * w;

const unsigned int64 valLeft = row[padLeft];
for (size_t i = 0; i < padLeft; ++i) {
row[i] = valLeft;
}

const unsigned int64 valRight = row[w - padRight - 1];
for (size_t i = w - padRight; i < w; ++i) {
row[i] = valRight;
}
}

// j
const unsigned int64* rowBottom = p + padBottom * w;
foreach (j = 0 ... padBottom) {
unsigned int64* row = p + j * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBottom[i];
}
}

const unsigned int64* rowTop = p + (padTop - 1) * w;
foreach (j = padTop... h - padTop) {
unsigned int64* row = p + j * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowTop[i];
}
}
}

export void padEdge2_float(uniform float p[], uniform size_t w, uniform size_t h,
uniform size_t padLeft, uniform size_t padRight,
uniform size_t padBottom, uniform size_t padTop) {
// i
foreach (j = padBottom... h - padTop) {
float* row = p + j * w;

const float valLeft = row[padLeft];
for (size_t i = 0; i < padLeft; ++i) {
row[i] = valLeft;
}

const float valRight = row[w - padRight - 1];
for (size_t i = w - padRight; i < w; ++i) {
row[i] = valRight;
}
}

// j
const float* rowBottom = p + padBottom * w;
foreach (j = 0 ... padBottom) {
float* row = p + j * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBottom[i];
}
}

const float* rowTop = p + (padTop - 1) * w;
foreach (j = padTop... h - padTop) {
float* row = p + j * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowTop[i];
}
}
}

export void padEdge2_double(uniform double p[], uniform size_t w, uniform size_t h,
uniform size_t padLeft, uniform size_t padRight,
uniform size_t padBottom, uniform size_t padTop) {
// i
foreach (j = padBottom... h - padTop) {
double* row = p + j * w;

const double valLeft = row[padLeft];
for (size_t i = 0; i < padLeft; ++i) {
row[i] = valLeft;
}

const double valRight = row[w - padRight - 1];
for (size_t i = w - padRight; i < w; ++i) {
row[i] = valRight;
}
}

// j
const double* rowBottom = p + padBottom * w;
foreach (j = 0 ... padBottom) {
double* row = p + j * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBottom[i];
}
}

const double* rowTop = p + (padTop - 1) * w;
foreach (j = padTop... h - padTop) {
double* row = p + j * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowTop[i];
}
}
}

export void padEdge3_int8_t(uniform int8 p[], uniform size_t w, uniform size_t h,
uniform size_t d, uniform size_t padLeft,
uniform size_t padRight, uniform size_t padBottom,
uniform size_t padTop, uniform size_t padBack,
uniform size_t padFront) {
// i
foreach (k = padBack... d - padFront) {
for (size_t j = padBottom; j < h - padTop; ++j) {
int8* row = p + (j + k * h) * w;

const int8 valLeft = row[padLeft];
for (size_t i = 0; i < padLeft; ++i) {
row[i] = valLeft;
}

const int8 valRight = row[w - padRight - 1];
for (size_t i = w - padRight; i < w; ++i) {
row[i] = valRight;
}
}
}

// j
foreach (k = padBack... d - padFront) {
const int8* rowBottom = p + (padBottom + k * h) * w;
for (size_t j = 0; j < padBottom; ++j) {
int8* row = p + (j + k * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBottom[i];
}
}

const int8* rowTop = p + (padTop - 1 + k * h) * w;
for (size_t j = padTop; j < h - padTop; ++j) {
int8* row = p + (j + k * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowTop[i];
}
}
}

// k
foreach (k = 0 ... padBack) {
for (size_t j = 0; j < h; ++j) {
int8* row = p + (j + k * h) * w;
int8* rowBack = p + (j + padBack * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBack[i];
}
}
}

foreach (k = d - padFront... padFront) {
for (size_t j = 0; j < h; ++j) {
int8* row = p + (j + k * h) * w;
int8* rowFront = p + (j + (padFront - 1) * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowFront[i];
}
}
}
}

export void padEdge3_uint8_t(uniform unsigned int8 p[], uniform size_t w, uniform size_t h,
uniform size_t d, uniform size_t padLeft,
uniform size_t padRight, uniform size_t padBottom,
uniform size_t padTop, uniform size_t padBack,
uniform size_t padFront) {
// i
foreach (k = padBack... d - padFront) {
for (size_t j = padBottom; j < h - padTop; ++j) {
unsigned int8* row = p + (j + k * h) * w;

const unsigned int8 valLeft = row[padLeft];
for (size_t i = 0; i < padLeft; ++i) {
row[i] = valLeft;
}

const unsigned int8 valRight = row[w - padRight - 1];
for (size_t i = w - padRight; i < w; ++i) {
row[i] = valRight;
}
}
}

// j
foreach (k = padBack... d - padFront) {
const unsigned int8* rowBottom = p + (padBottom + k * h) * w;
for (size_t j = 0; j < padBottom; ++j) {
unsigned int8* row = p + (j + k * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBottom[i];
}
}

const unsigned int8* rowTop = p + (padTop - 1 + k * h) * w;
for (size_t j = padTop; j < h - padTop; ++j) {
unsigned int8* row = p + (j + k * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowTop[i];
}
}
}

// k
foreach (k = 0 ... padBack) {
for (size_t j = 0; j < h; ++j) {
unsigned int8* row = p + (j + k * h) * w;
unsigned int8* rowBack = p + (j + padBack * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBack[i];
}
}
}

foreach (k = d - padFront... padFront) {
for (size_t j = 0; j < h; ++j) {
unsigned int8* row = p + (j + k * h) * w;
unsigned int8* rowFront = p + (j + (padFront - 1) * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowFront[i];
}
}
}
}

export void padEdge3_int16_t(uniform int16 p[], uniform size_t w, uniform size_t h,
uniform size_t d, uniform size_t padLeft,
uniform size_t padRight, uniform size_t padBottom,
uniform size_t padTop, uniform size_t padBack,
uniform size_t padFront) {
// i
foreach (k = padBack... d - padFront) {
for (size_t j = padBottom; j < h - padTop; ++j) {
int16* row = p + (j + k * h) * w;

const int16 valLeft = row[padLeft];
for (size_t i = 0; i < padLeft; ++i) {
row[i] = valLeft;
}

const int16 valRight = row[w - padRight - 1];
for (size_t i = w - padRight; i < w; ++i) {
row[i] = valRight;
}
}
}

// j
foreach (k = padBack... d - padFront) {
const int16* rowBottom = p + (padBottom + k * h) * w;
for (size_t j = 0; j < padBottom; ++j) {
int16* row = p + (j + k * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBottom[i];
}
}

const int16* rowTop = p + (padTop - 1 + k * h) * w;
for (size_t j = padTop; j < h - padTop; ++j) {
int16* row = p + (j + k * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowTop[i];
}
}
}

// k
foreach (k = 0 ... padBack) {
for (size_t j = 0; j < h; ++j) {
int16* row = p + (j + k * h) * w;
int16* rowBack = p + (j + padBack * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBack[i];
}
}
}

foreach (k = d - padFront... padFront) {
for (size_t j = 0; j < h; ++j) {
int16* row = p + (j + k * h) * w;
int16* rowFront = p + (j + (padFront - 1) * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowFront[i];
}
}
}
}

export void padEdge3_uint16_t(uniform unsigned int16 p[], uniform size_t w, uniform size_t h,
uniform size_t d, uniform size_t padLeft,
uniform size_t padRight, uniform size_t padBottom,
uniform size_t padTop, uniform size_t padBack,
uniform size_t padFront) {
// i
foreach (k = padBack... d - padFront) {
for (size_t j = padBottom; j < h - padTop; ++j) {
unsigned int16* row = p + (j + k * h) * w;

const unsigned int16 valLeft = row[padLeft];
for (size_t i = 0; i < padLeft; ++i) {
row[i] = valLeft;
}

const unsigned int16 valRight = row[w - padRight - 1];
for (size_t i = w - padRight; i < w; ++i) {
row[i] = valRight;
}
}
}

// j
foreach (k = padBack... d - padFront) {
const unsigned int16* rowBottom = p + (padBottom + k * h) * w;
for (size_t j = 0; j < padBottom; ++j) {
unsigned int16* row = p + (j + k * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBottom[i];
}
}

const unsigned int16* rowTop = p + (padTop - 1 + k * h) * w;
for (size_t j = padTop; j < h - padTop; ++j) {
unsigned int16* row = p + (j + k * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowTop[i];
}
}
}

// k
foreach (k = 0 ... padBack) {
for (size_t j = 0; j < h; ++j) {
unsigned int16* row = p + (j + k * h) * w;
unsigned int16* rowBack = p + (j + padBack * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBack[i];
}
}
}

foreach (k = d - padFront... padFront) {
for (size_t j = 0; j < h; ++j) {
unsigned int16* row = p + (j + k * h) * w;
unsigned int16* rowFront = p + (j + (padFront - 1) * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowFront[i];
}
}
}
}

export void padEdge3_int32_t(uniform int32 p[], uniform size_t w, uniform size_t h,
uniform size_t d, uniform size_t padLeft,
uniform size_t padRight, uniform size_t padBottom,
uniform size_t padTop, uniform size_t padBack,
uniform size_t padFront) {
// i
foreach (k = padBack... d - padFront) {
for (size_t j = padBottom; j < h - padTop; ++j) {
int32* row = p + (j + k * h) * w;

const int32 valLeft = row[padLeft];
for (size_t i = 0; i < padLeft; ++i) {
row[i] = valLeft;
}

const int32 valRight = row[w - padRight - 1];
for (size_t i = w - padRight; i < w; ++i) {
row[i] = valRight;
}
}
}

// j
foreach (k = padBack... d - padFront) {
const int32* rowBottom = p + (padBottom + k * h) * w;
for (size_t j = 0; j < padBottom; ++j) {
int32* row = p + (j + k * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBottom[i];
}
}

const int32* rowTop = p + (padTop - 1 + k * h) * w;
for (size_t j = padTop; j < h - padTop; ++j) {
int32* row = p + (j + k * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowTop[i];
}
}
}

// k
foreach (k = 0 ... padBack) {
for (size_t j = 0; j < h; ++j) {
int32* row = p + (j + k * h) * w;
int32* rowBack = p + (j + padBack * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBack[i];
}
}
}

foreach (k = d - padFront... padFront) {
for (size_t j = 0; j < h; ++j) {
int32* row = p + (j + k * h) * w;
int32* rowFront = p + (j + (padFront - 1) * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowFront[i];
}
}
}
}

export void padEdge3_uint32_t(uniform unsigned int32 p[], uniform size_t w, uniform size_t h,
uniform size_t d, uniform size_t padLeft,
uniform size_t padRight, uniform size_t padBottom,
uniform size_t padTop, uniform size_t padBack,
uniform size_t padFront) {
// i
foreach (k = padBack... d - padFront) {
for (size_t j = padBottom; j < h - padTop; ++j) {
unsigned int32* row = p + (j + k * h) * w;

const unsigned int32 valLeft = row[padLeft];
for (size_t i = 0; i < padLeft; ++i) {
row[i] = valLeft;
}

const unsigned int32 valRight = row[w - padRight - 1];
for (size_t i = w - padRight; i < w; ++i) {
row[i] = valRight;
}
}
}

// j
foreach (k = padBack... d - padFront) {
const unsigned int32* rowBottom = p + (padBottom + k * h) * w;
for (size_t j = 0; j < padBottom; ++j) {
unsigned int32* row = p + (j + k * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBottom[i];
}
}

const unsigned int32* rowTop = p + (padTop - 1 + k * h) * w;
for (size_t j = padTop; j < h - padTop; ++j) {
unsigned int32* row = p + (j + k * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowTop[i];
}
}
}

// k
foreach (k = 0 ... padBack) {
for (size_t j = 0; j < h; ++j) {
unsigned int32* row = p + (j + k * h) * w;
unsigned int32* rowBack = p + (j + padBack * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBack[i];
}
}
}

foreach (k = d - padFront... padFront) {
for (size_t j = 0; j < h; ++j) {
unsigned int32* row = p + (j + k * h) * w;
unsigned int32* rowFront = p + (j + (padFront - 1) * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowFront[i];
}
}
}
}

export void padEdge3_int64_t(uniform int64 p[], uniform size_t w, uniform size_t h,
uniform size_t d, uniform size_t padLeft,
uniform size_t padRight, uniform size_t padBottom,
uniform size_t padTop, uniform size_t padBack,
uniform size_t padFront) {
// i
foreach (k = padBack... d - padFront) {
for (size_t j = padBottom; j < h - padTop; ++j) {
int64* row = p + (j + k * h) * w;

const int64 valLeft = row[padLeft];
for (size_t i = 0; i < padLeft; ++i) {
row[i] = valLeft;
}

const int64 valRight = row[w - padRight - 1];
for (size_t i = w - padRight; i < w; ++i) {
row[i] = valRight;
}
}
}

// j
foreach (k = padBack... d - padFront) {
const int64* rowBottom = p + (padBottom + k * h) * w;
for (size_t j = 0; j < padBottom; ++j) {
int64* row = p + (j + k * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBottom[i];
}
}

const int64* rowTop = p + (padTop - 1 + k * h) * w;
for (size_t j = padTop; j < h - padTop; ++j) {
int64* row = p + (j + k * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowTop[i];
}
}
}

// k
foreach (k = 0 ... padBack) {
for (size_t j = 0; j < h; ++j) {
int64* row = p + (j + k * h) * w;
int64* rowBack = p + (j + padBack * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBack[i];
}
}
}

foreach (k = d - padFront... padFront) {
for (size_t j = 0; j < h; ++j) {
int64* row = p + (j + k * h) * w;
int64* rowFront = p + (j + (padFront - 1) * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowFront[i];
}
}
}
}

export void padEdge3_uint64_t(uniform unsigned int64 p[], uniform size_t w, uniform size_t h,
uniform size_t d, uniform size_t padLeft,
uniform size_t padRight, uniform size_t padBottom,
uniform size_t padTop, uniform size_t padBack,
uniform size_t padFront) {
// i
foreach (k = padBack... d - padFront) {
for (size_t j = padBottom; j < h - padTop; ++j) {
unsigned int64* row = p + (j + k * h) * w;

const unsigned int64 valLeft = row[padLeft];
for (size_t i = 0; i < padLeft; ++i) {
row[i] = valLeft;
}

const unsigned int64 valRight = row[w - padRight - 1];
for (size_t i = w - padRight; i < w; ++i) {
row[i] = valRight;
}
}
}

// j
foreach (k = padBack... d - padFront) {
const unsigned int64* rowBottom = p + (padBottom + k * h) * w;
for (size_t j = 0; j < padBottom; ++j) {
unsigned int64* row = p + (j + k * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBottom[i];
}
}

const unsigned int64* rowTop = p + (padTop - 1 + k * h) * w;
for (size_t j = padTop; j < h - padTop; ++j) {
unsigned int64* row = p + (j + k * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowTop[i];
}
}
}

// k
foreach (k = 0 ... padBack) {
for (size_t j = 0; j < h; ++j) {
unsigned int64* row = p + (j + k * h) * w;
unsigned int64* rowBack = p + (j + padBack * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBack[i];
}
}
}

foreach (k = d - padFront... padFront) {
for (size_t j = 0; j < h; ++j) {
unsigned int64* row = p + (j + k * h) * w;
unsigned int64* rowFront = p + (j + (padFront - 1) * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowFront[i];
}
}
}
}

export void padEdge3_float(uniform float p[], uniform size_t w, uniform size_t h,
uniform size_t d, uniform size_t padLeft,
uniform size_t padRight, uniform size_t padBottom,
uniform size_t padTop, uniform size_t padBack,
uniform size_t padFront) {
// i
foreach (k = padBack... d - padFront) {
for (size_t j = padBottom; j < h - padTop; ++j) {
float* row = p + (j + k * h) * w;

const float valLeft = row[padLeft];
for (size_t i = 0; i < padLeft; ++i) {
row[i] = valLeft;
}

const float valRight = row[w - padRight - 1];
for (size_t i = w - padRight; i < w; ++i) {
row[i] = valRight;
}
}
}

// j
foreach (k = padBack... d - padFront) {
const float* rowBottom = p + (padBottom + k * h) * w;
for (size_t j = 0; j < padBottom; ++j) {
float* row = p + (j + k * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBottom[i];
}
}

const float* rowTop = p + (padTop - 1 + k * h) * w;
for (size_t j = padTop; j < h - padTop; ++j) {
float* row = p + (j + k * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowTop[i];
}
}
}

// k
foreach (k = 0 ... padBack) {
for (size_t j = 0; j < h; ++j) {
float* row = p + (j + k * h) * w;
float* rowBack = p + (j + padBack * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBack[i];
}
}
}

foreach (k = d - padFront... padFront) {
for (size_t j = 0; j < h; ++j) {
float* row = p + (j + k * h) * w;
float* rowFront = p + (j + (padFront - 1) * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowFront[i];
}
}
}
}

export void padEdge3_double(uniform double p[], uniform size_t w, uniform size_t h,
uniform size_t d, uniform size_t padLeft,
uniform size_t padRight, uniform size_t padBottom,
uniform size_t padTop, uniform size_t padBack,
uniform size_t padFront) {
// i
foreach (k = padBack... d - padFront) {
for (size_t j = padBottom; j < h - padTop; ++j) {
double* row = p + (j + k * h) * w;

const double valLeft = row[padLeft];
for (size_t i = 0; i < padLeft; ++i) {
row[i] = valLeft;
}

const double valRight = row[w - padRight - 1];
for (size_t i = w - padRight; i < w; ++i) {
row[i] = valRight;
}
}
}

// j
foreach (k = padBack... d - padFront) {
const double* rowBottom = p + (padBottom + k * h) * w;
for (size_t j = 0; j < padBottom; ++j) {
double* row = p + (j + k * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBottom[i];
}
}

const double* rowTop = p + (padTop - 1 + k * h) * w;
for (size_t j = padTop; j < h - padTop; ++j) {
double* row = p + (j + k * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowTop[i];
}
}
}

// k
foreach (k = 0 ... padBack) {
for (size_t j = 0; j < h; ++j) {
double* row = p + (j + k * h) * w;
double* rowBack = p + (j + padBack * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowBack[i];
}
}
}

foreach (k = d - padFront... padFront) {
for (size_t j = 0; j < h; ++j) {
double* row = p + (j + k * h) * w;
double* rowFront = p + (j + (padFront - 1) * h) * w;
for (size_t i = 0; i < w; ++i) {
row[i] = rowFront[i];
}
}
}
}