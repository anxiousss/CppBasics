#include <vector>
#include <iostream>
#include <cassert>

template <typename T>
class Polynomial {
public:
    std::vector<T> polynomial;
    inline static const T ZERO = T{0};

    Polynomial(const std::vector<T>& pol) {
        if (pol.empty())
            polynomial = std::vector<T>(1);
        else
            polynomial = pol;

        check_zeros();
    }

    Polynomial(const T& value = T{0}) {
        polynomial = std::vector<T>(1, value);
    }

    Polynomial(const Polynomial<T>& other) {
        polynomial = other.polynomial;
    }

    Polynomial(Polynomial<T>&& other) noexcept : polynomial(std::move(other.polynomial)) {}

    template<typename Iter>
    Polynomial(Iter begin, Iter end) {
        while (begin != end) {
            polynomial.push_back(*begin);
            ++begin;
        }
        if (polynomial.empty())
            polynomial.push_back(T{0});

        check_zeros();
    }

    void check_zeros() {
        size_t new_size = polynomial.size();
        while (new_size > 0 && polynomial[new_size - 1] == T{0}) {
            --new_size;
        }
        if (new_size == 0) {
            polynomial.assign(1, T{0});
        } else {
            polynomial.resize(new_size);
        }
    }

    const T& operator[](size_t degree) const {
        if (degree >= polynomial.size()) return ZERO;
        return polynomial[degree];
    }


    int Degree() const {
        return (polynomial.size() == 1 && polynomial[0] == T{0}) ? -1 : static_cast<int>(polynomial.size()) - 1;
    }

    T operator()(const T& point) const {
        if (polynomial.size() == 1)
            return polynomial[0];

        T res{0};
        for (int i = polynomial.size() - 1; i > 0; --i) {
            res += polynomial[i];
            res *= point;
        }

        res += polynomial[0];
        return res;
    }

    [[nodiscard]] auto begin() const {
        return polynomial.cbegin();
    }

    [[nodiscard]] auto end() const {
        return polynomial.cend();
    }
};

template <typename T>
bool operator==(const Polynomial<T>& a, const Polynomial<T>& b) {
    if (a.polynomial.size() != b.polynomial.size())
        return false;

    for (size_t i = 0; i < a.polynomial.size(); ++i) {
        if (a.polynomial[i] != b.polynomial[i])
            return false;
    }
    return true;
}

template <typename T>
bool operator==(const Polynomial<T>& a, const T& scalar) {
    return a.polynomial.size() == 1 && a.polynomial[0] == scalar;
}

template <typename T>
bool operator==( const T& scalar, const Polynomial<T>& a) {
    return a == scalar;
}

template <typename T>
bool operator!=(const Polynomial<T>& a, const Polynomial<T>& b) {
    return  !(a == b);
}

template <typename T>
bool operator!=(const Polynomial<T>& a, const T& scalar) {
    return !(a == scalar);
}

template <typename T>
bool operator!=( const T& scalar, const Polynomial<T>& a) {
    return a != scalar;
}

template <typename T>
Polynomial<T>& operator+=(Polynomial<T>& a, const Polynomial<T>& b) {
    if (a.polynomial.size() <= b.polynomial.size()) {
        a.polynomial.resize(b.polynomial.size());
    }
    for (size_t i = 0; i < b.polynomial.size(); ++i) {
        a.polynomial[i] += b.polynomial[i];
    }

    a.check_zeros();
    return a;
}

template <typename T>
Polynomial<T> operator+(const Polynomial<T>& a, const Polynomial<T>& b) {
    auto tmp(a);
    tmp += b;
    return tmp;
}

template <typename T>
Polynomial<T>& operator+=(Polynomial<T>& a, const T& scalar) {
    a.polynomial[0] += scalar;
    a.check_zeros();
    return a;
}

template <typename T>
Polynomial<T> operator+(const Polynomial<T>& a, const T& scalar) {
    auto tmp(a);
    tmp += scalar;
    return tmp;
}

template <typename T>
Polynomial<T> operator+(const T& scalar, const Polynomial<T>& a) {
    return a + scalar;
}

template <typename T>
Polynomial<T>& operator-=(Polynomial<T>& a, const Polynomial<T>& b) {
    if (a.polynomial.size() <= b.polynomial.size()) {
        a.polynomial.resize(b.polynomial.size());
    }
    for (size_t i = 0; i < b.polynomial.size(); ++i) {
        a.polynomial[i] -= b.polynomial[i];
    }

    a.check_zeros();
    return a;
}

template <typename T>
Polynomial<T> operator-(const Polynomial<T>& a, const Polynomial<T>& b) {
    auto tmp(a);
    tmp -= b;
    return tmp;
}

template <typename T>
Polynomial<T>& operator-=(Polynomial<T>& a, const T& scalar) {
    a.polynomial[0] -= scalar;
    a.check_zeros();
    return a;
}

template <typename T>
Polynomial<T> operator-(const Polynomial<T>& a, const T& scalar) {
    auto tmp(a);
    tmp -= scalar;
    return tmp;
}

template <typename T>
Polynomial<T> operator-(const T& scalar, const Polynomial<T>& a) {
    return Polynomial<T>(scalar) - a;
}

template <typename T>
Polynomial<T>& operator*=(Polynomial<T>& a, const Polynomial<T>& b) {
    size_t polynom_size = a.polynomial.size() + b.polynomial.size() - 1;
    std::vector<T> mul(polynom_size, T{0});
    for (size_t i = 0; i < a.polynomial.size(); ++i) {
        for (size_t j = 0; j < b.polynomial.size(); ++j) {
            mul[i + j] += a.polynomial[i] * b.polynomial[j];
        }
    }

    a.polynomial = std::move(mul);
    a.check_zeros();
    return a;
}
template <typename T>
Polynomial<T>& operator*=(Polynomial<T>& a, const T& scalar) {
    for (size_t i = 0; i < a.polynomial.size(); ++i) {
        a.polynomial[i] *= scalar;
    }
    a.check_zeros();
    return a;
}

template <typename T>
Polynomial<T> operator*(const Polynomial<T>& a, const Polynomial<T>& b) {
    auto tmp(a);
    tmp *= b;
    return tmp;
}

template <typename T>
Polynomial<T> operator*(const Polynomial<T>& a, const T& scalar) {
    auto tmp(a);
    tmp *= scalar;
    return tmp;
}

template <typename T>
Polynomial<T> operator*(const T& scalar, const Polynomial<T>& a) {
    return a * scalar;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Polynomial<T>& polynomial) {
    for (size_t i = polynomial.polynomial.size(); i-- > 0; ) {
        out << polynomial.polynomial[i] << ' ';
    }
    return out;
}

