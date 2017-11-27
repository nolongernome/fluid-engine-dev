// Copyright (c) 2017 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <pch.h>

#include <core_api_array_ispc_kernels_ispc.h>
#include <core_api_utils.h>

#include <array>

namespace jet {

namespace core {

namespace internal {

namespace ispc {

template <typename Subclass>
class UnaryOperator : public TypeDispatcher<UnaryOperator<Subclass>> {
 public:
    template <typename T>
    void computeS(const BufferView& a, BufferView* result) const {
        const auto& subc = (*this)();
        const T ap = a.cast<T>()[0];
        T* rp = result->cast<T>();
        subc(ap, result->length(), rp);
    }

    template <typename T>
    void computeV(const BufferView& a, BufferView* result) const {
        const auto& subc = (*this)();
        const T* ap = a.cast<T>();
        T* rp = result->cast<T>();
        subc(ap, result->length(), rp);
    }

    template <typename T>
    void computeTyped(const BufferView& a, BufferView* result) const {
        if (a.length() == 1) {
            computeS<T>(a, result);
        } else {
            computeV<T>(a, result);
        }
    }

 private:
    //! Returns actual implementation (the subclass).
    const Subclass& operator()() const {
        return static_cast<const Subclass&>(*this);
    }
};

template <typename Subclass>
class BinaryOperator : public TypeDispatcher<BinaryOperator<Subclass>> {
 public:
    template <typename T>
    void computeSV(const BufferView& a, const BufferView& b,
                   BufferView* result) const {
        const auto& subc = (*this)();
        const T ap = a.cast<T>()[0];
        const T* bp = b.cast<T>();
        T* rp = result->cast<T>();
        subc(ap, bp, result->length(), rp);
    }

    template <typename T>
    void computeVV(const BufferView& a, const BufferView& b,
                   BufferView* result) const {
        const auto& subc = (*this)();
        const auto* ap = a.cast<T>();
        const auto* bp = b.cast<T>();
        auto* rp = result->cast<T>();
        subc(ap, bp, result->length(), rp);
    }

    template <typename T>
    void computeTyped(const BufferView& a, const BufferView& b,
                      BufferView* result) const {
        if (a.length() == 1) {
            computeSV<T>(a, b, result);
        } else {
            computeVV<T>(a, b, result);
        }
    }

 private:
    //! Returns actual implementation (the subclass).
    const Subclass& operator()() const {
        return static_cast<const Subclass&>(*this);
    }
};

template <typename Subclass>
class TernaryOperator : public TypeDispatcher<TernaryOperator<Subclass>> {
 public:
    template <typename T>
    void computeSVV(const BufferView& a, const BufferView& b,
                    const BufferView& c, BufferView* result) const {
        const auto& subc = (*this)();
        const T ap = a.cast<T>()[0];
        const T* bp = b.cast<T>();
        const T* cp = c.cast<T>();
        T* rp = result->cast<T>();
        subc(ap, bp, cp, result->length(), rp);
    }

    template <typename T>
    void computeVVV(const BufferView& a, const BufferView& b,
                    const BufferView& c, BufferView* result) const {
        const auto& subc = (*this)();
        const auto* ap = a.cast<T>();
        const auto* bp = b.cast<T>();
        const auto* cp = c.cast<T>();
        auto* rp = result->cast<T>();
        subc(ap, bp, cp, result->length(), rp);
    }

    template <typename T>
    void computeTyped(const BufferView& a, const BufferView& b,
                      const BufferView& c, BufferView* result) const {
        if (a.length() == 1) {
            computeSVV<T>(a, b, c, result);
        } else {
            computeVVV<T>(a, b, c, result);
        }
    }

 private:
    //! Returns actual implementation (the subclass).
    const Subclass& operator()() const {
        return static_cast<const Subclass&>(*this);
    }
};

#define UNARY_S_OPERATOR_ISPC(funcName, type)                     \
    void operator()(const type a, size_t n, type* result) const { \
        using namespace ::ispc;                                   \
        funcName##_##type(a, n, result);                          \
    }

#define UNARY_V_OPERATOR_ISPC(funcName, type)                      \
    void operator()(const type* a, size_t n, type* result) const { \
        using namespace ::ispc;                                    \
        funcName##_##type(a, n, result);                           \
    }

#define BINARY_S_OPERATOR_ISPC(funcName, type)                           \
    void operator()(const type a, const type* b, size_t n, type* result) \
        const {                                                          \
        using namespace ::ispc;                                          \
        funcName##_##type(a, b, n, result);                              \
    }

#define BINARY_V_OPERATOR_ISPC(funcName, type)                            \
    void operator()(const type* a, const type* b, size_t n, type* result) \
        const {                                                           \
        using namespace ::ispc;                                           \
        funcName##_##type(a, b, n, result);                               \
    }

#define TERNARY_S_OPERATOR_ISPC(funcName, type)                           \
    void operator()(const type a, const type* b, const type* c, size_t n, \
                    type* result) const {                                 \
        using namespace ::ispc;                                           \
        funcName##_##type(a, b, c, n, result);                            \
    }

#define TERNARY_V_OPERATOR_ISPC(funcName, type)                            \
    void operator()(const type* a, const type* b, const type* c, size_t n, \
                    type* result) const {                                  \
        using namespace ::ispc;                                            \
        funcName##_##type(a, b, c, n, result);                             \
    }

#define OPERATOR_ALL_TYPES_ISPC(wrapperName, funcName) \
    wrapperName(funcName, int8_t);                     \
    wrapperName(funcName, uint8_t);                    \
    wrapperName(funcName, int16_t);                    \
    wrapperName(funcName, uint16_t);                   \
    wrapperName(funcName, int32_t);                    \
    wrapperName(funcName, uint32_t);                   \
    wrapperName(funcName, int64_t);                    \
    wrapperName(funcName, uint64_t);                   \
    wrapperName(funcName, float);                      \
    wrapperName(funcName, double);

struct CopyOperator : public UnaryOperator<CopyOperator> {
    OPERATOR_ALL_TYPES_ISPC(UNARY_S_OPERATOR_ISPC, copyKernelS)
    OPERATOR_ALL_TYPES_ISPC(UNARY_V_OPERATOR_ISPC, copyKernelV)
};

struct AddOperator : public BinaryOperator<AddOperator> {
    OPERATOR_ALL_TYPES_ISPC(BINARY_S_OPERATOR_ISPC, addKernelS)
    OPERATOR_ALL_TYPES_ISPC(BINARY_V_OPERATOR_ISPC, addKernelV)
};

struct SubOperator : public BinaryOperator<SubOperator> {
    OPERATOR_ALL_TYPES_ISPC(BINARY_S_OPERATOR_ISPC, subKernelS)
    OPERATOR_ALL_TYPES_ISPC(BINARY_V_OPERATOR_ISPC, subKernelV)
};

struct MulOperator : public BinaryOperator<MulOperator> {
    OPERATOR_ALL_TYPES_ISPC(BINARY_S_OPERATOR_ISPC, mulKernelS)
    OPERATOR_ALL_TYPES_ISPC(BINARY_V_OPERATOR_ISPC, mulKernelV)
};

struct DivOperator : public BinaryOperator<DivOperator> {
    OPERATOR_ALL_TYPES_ISPC(BINARY_S_OPERATOR_ISPC, divKernelS)
    OPERATOR_ALL_TYPES_ISPC(BINARY_V_OPERATOR_ISPC, divKernelV)
};

struct AxpyOperator : public TernaryOperator<AxpyOperator> {
    OPERATOR_ALL_TYPES_ISPC(TERNARY_S_OPERATOR_ISPC, axpyKernelS)
    OPERATOR_ALL_TYPES_ISPC(TERNARY_V_OPERATOR_ISPC, axpyKernelV)
};

#define PAD_EDGE1_OPERATOR_ISPC(funcName, type)                         \
    void operator()(type* p, size_t n, size_t padLeft, size_t padRight) \
        const {                                                         \
        using namespace ::ispc;                                         \
        funcName##_##type(p, n, padLeft, padRight);                     \
    }

#define PAD_EDGE2_OPERATOR_ISPC(funcName, type)                               \
    void operator()(type* p, size_t w, size_t h, size_t padLeft,              \
                    size_t padRight, size_t padBottom, size_t padTop) const { \
        using namespace ::ispc;                                               \
        funcName##_##type(p, w, h, padLeft, padRight, padBottom, padTop);     \
    }

#define PAD_EDGE3_OPERATOR_ISPC(funcName, type)                             \
    void operator()(type* p, size_t w, size_t h, size_t d, size_t padLeft,  \
                    size_t padRight, size_t padBottom, size_t padTop,       \
                    size_t padBack, size_t padFront) const {                \
        using namespace ::ispc;                                             \
        funcName##_##type(p, w, h, d, padLeft, padRight, padBottom, padTop, \
                          padBack, padFront);                               \
    }

struct PadEdgeOperator : public DimDispatcher<PadEdgeOperator> {
    template <typename T>
    void computeTyped1(
        BufferView* input,
        const std::array<std::array<size_t, 2>, 3>& padWidth) const {
        T* p = input->cast<T>();
        size_t n = input->shape[0];
        const size_t padLeft = padWidth[0][0];
        const size_t padRight = padWidth[0][1];

        (*this)(p, n, padLeft, padRight);
    }

    template <typename T>
    void computeTyped2(
        BufferView* input,
        const std::array<std::array<size_t, 2>, 3>& padWidth) const {
        T* p = input->cast<T>();
        size_t w = input->shape[0];
        size_t h = input->shape[1];
        const size_t padLeft = padWidth[0][0];
        const size_t padRight = padWidth[0][1];
        const size_t padBottom = padWidth[1][0];
        const size_t padTop = padWidth[1][1];

        (*this)(p, w, h, padLeft, padRight, padBottom, padTop);
    }

    template <typename T>
    void computeTyped3(
        BufferView* input,
        const std::array<std::array<size_t, 2>, 3>& padWidth) const {
        T* p = input->cast<T>();
        size_t w = input->shape[0];
        size_t h = input->shape[1];
        size_t d = input->shape[2];
        const size_t padLeft = padWidth[0][0];
        const size_t padRight = padWidth[0][1];
        const size_t padBottom = padWidth[1][0];
        const size_t padTop = padWidth[1][1];
        const size_t padBack = padWidth[2][0];
        const size_t padFront = padWidth[2][1];

        (*this)(p, w, h, d, padLeft, padRight, padBottom, padTop, padBack,
                padFront);
    }

    OPERATOR_ALL_TYPES_ISPC(PAD_EDGE1_OPERATOR_ISPC, padEdge1)
    OPERATOR_ALL_TYPES_ISPC(PAD_EDGE2_OPERATOR_ISPC, padEdge2)
    OPERATOR_ALL_TYPES_ISPC(PAD_EDGE3_OPERATOR_ISPC, padEdge3)
};

void copy(const BufferView& a, BufferView* result) {
    CopyOperator op;
    op.compute(a.dataType, a, result);
}

void add(const BufferView& a, const BufferView& b, BufferView* result) {
    AddOperator op;
    op.compute(a.dataType, a, b, result);
}

void sub(const BufferView& a, const BufferView& b, BufferView* result) {
    SubOperator op;
    op.compute(a.dataType, a, b, result);
}

void mul(const BufferView& a, const BufferView& b, BufferView* result) {
    MulOperator op;
    op.compute(a.dataType, a, b, result);
}

void div(const BufferView& a, const BufferView& b, BufferView* result) {
    DivOperator op;
    op.compute(a.dataType, a, b, result);
}

void axpy(const BufferView& a, const BufferView& x, const BufferView& y,
          BufferView* result) {
    AxpyOperator op;
    op.compute(a.dataType, a, x, y, result);
}

void padEdge(BufferView* input,
             const std::array<std::array<size_t, 2>, 3>& padWidth) {
    PadEdgeOperator op;
    op.compute(input->dataType, input->ndim, input, padWidth);
}

}  // namespace ispc

}  // namespace internal

}  // namespace core

}  // namespace jet
