// Copyright (c) 2017 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <pch.h>

#include <core_api_utils.h>

#include <jet/parallel.h>

#include <array>

namespace jet {

namespace core {

namespace internal {

namespace cpu {

template <typename Subclass>
class UnaryOperator : public TypeDispatcher<UnaryOperator<Subclass>> {
 public:
    template <typename T>
    void computeS(const BufferView& a, BufferView* result) const {
        const auto& subc = (*this)();
        const T ap = a.cast<T>()[0];
        T* rp = result->cast<T>();
        const T r = subc(ap);
        parallelFor(kZeroSize, result->length(), [&](size_t i) { rp[i] = r; });
    }

    template <typename T>
    void computeV(const BufferView& a, BufferView* result) const {
        const auto& subc = (*this)();
        const auto* ap = a.cast<T>();
        auto* rp = result->cast<T>();
        parallelFor(kZeroSize, a.length(),
                    [&](size_t i) { rp[i] = subc(ap[i]); });
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
        parallelFor(kZeroSize, b.length(),
                    [&](size_t i) { rp[i] = subc(ap, bp[i]); });
    }

    template <typename T>
    void computeVV(const BufferView& a, const BufferView& b,
                   BufferView* result) const {
        const auto& subc = (*this)();
        const auto* ap = a.cast<T>();
        const auto* bp = b.cast<T>();
        auto* rp = result->cast<T>();
        parallelFor(kZeroSize, a.length(),
                    [&](size_t i) { rp[i] = subc(ap[i], bp[i]); });
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
        parallelFor(kZeroSize, b.length(),
                    [&](size_t i) { rp[i] = subc(ap, bp[i], cp[i]); });
    }

    template <typename T>
    void computeVVV(const BufferView& a, const BufferView& b,
                    const BufferView& c, BufferView* result) const {
        const auto& subc = (*this)();
        const auto* ap = a.cast<T>();
        const auto* bp = b.cast<T>();
        const auto* cp = c.cast<T>();
        auto* rp = result->cast<T>();
        parallelFor(kZeroSize, a.length(),
                    [&](size_t i) { rp[i] = subc(ap[i], bp[i], cp[i]); });
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

struct CopyOperator : public UnaryOperator<CopyOperator> {
    template <typename T>
    T operator()(const T a) const {
        return a;
    }
};

struct AddOperator : public BinaryOperator<AddOperator> {
    template <typename T>
    T operator()(const T a, const T b) const {
        return a + b;
    }
};

struct SubOperator : public BinaryOperator<SubOperator> {
    template <typename T>
    T operator()(const T a, const T b) const {
        return a - b;
    }
};

struct MulOperator : public BinaryOperator<MulOperator> {
    template <typename T>
    T operator()(const T a, const T b) const {
        return a * b;
    }
};

struct DivOperator : public BinaryOperator<DivOperator> {
    template <typename T>
    T operator()(const T a, const T b) const {
        return a / b;
    }
};

struct AxpyOperator : public TernaryOperator<AxpyOperator> {
    template <typename T>
    T operator()(const T a, const T x, const T y) const {
        return a * x + y;
    }
};

struct PadEdgeOperator : public DimDispatcher<PadEdgeOperator> {
    template <typename T>
    void computeTyped1(
        BufferView* input,
        const std::array<std::array<size_t, 2>, 3>& padWidth) const {
        T* p = input->cast<T>();
        size_t n = input->shape[0];
        const size_t padLeft = padWidth[0][0];
        const size_t padRight = padWidth[0][1];

        const T valLeft = p[padLeft];
        for (size_t i = 0; i < padLeft; ++i) {
            p[i] = valLeft;
        }

        const T valRight = p[n - padRight - 1];
        for (size_t i = n - padRight - 1; i < n; ++i) {
            p[i] = valRight;
        }
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

        // i
        for (size_t j = padBottom; j < h - padTop; ++j) {
            T* row = p + j * w;

            const T valLeft = row[padLeft];
            for (size_t i = 0; i < padLeft; ++i) {
                row[i] = valLeft;
            }

            const T valRight = row[w - padRight - 1];
            for (size_t i = w - padRight; i < w; ++i) {
                row[i] = valRight;
            }
        }

        // j
        const T* rowBottom = p + padBottom * w;
        for (size_t j = 0; j < padBottom; ++j) {
            T* row = p + j * w;
            for (size_t i = 0; i < w; ++i) {
                row[i] = rowBottom[i];
            }
        }

        const T* rowTop = p + (padTop - 1) * w;
        for (size_t j = padTop; j < h - padTop; ++j) {
            T* row = p + j * w;
            for (size_t i = 0; i < w; ++i) {
                row[i] = rowTop[i];
            }
        }
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

        // i
        for (size_t k = padBack; k < d - padFront; ++k) {
            for (size_t j = padBottom; j < h - padTop; ++j) {
                T* row = p + (j + k * h) * w;

                const T valLeft = row[padLeft];
                for (size_t i = 0; i < padLeft; ++i) {
                    row[i] = valLeft;
                }

                const T valRight = row[w - padRight - 1];
                for (size_t i = w - padRight; i < w; ++i) {
                    row[i] = valRight;
                }
            }
        }

        // j
        for (size_t k = padBack; k < d - padFront; ++k) {
            const T* rowBottom = p + (padBottom + k * h) * w;
            for (size_t j = 0; j < padBottom; ++j) {
                T* row = p + (j + k * h) * w;
                for (size_t i = 0; i < w; ++i) {
                    row[i] = rowBottom[i];
                }
            }

            const T* rowTop = p + (padTop - 1 + k * h) * w;
            for (size_t j = padTop; j < h - padTop; ++j) {
                T* row = p + (j + k * h) * w;
                for (size_t i = 0; i < w; ++i) {
                    row[i] = rowTop[i];
                }
            }
        }

        // k
        for (size_t k = 0; k < padBack; ++k) {
            for (size_t j = 0; j < h; ++j) {
                T* row = p + (j + k * h) * w;
                T* rowBack = p + (j + padBack * h) * w;
                for (size_t i = 0; i < w; ++i) {
                    row[i] = rowBack[i];
                }
            }
        }

        for (size_t k = d - padFront; k < padFront; ++k) {
            for (size_t j = 0; j < h; ++j) {
                T* row = p + (j + k * h) * w;
                T* rowFront = p + (j + (padFront - 1) * h) * w;
                for (size_t i = 0; i < w; ++i) {
                    row[i] = rowFront[i];
                }
            }
        }
    }
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

}  // namespace cpu

}  // namespace internal

}  // namespace core

}  // namespace jet
