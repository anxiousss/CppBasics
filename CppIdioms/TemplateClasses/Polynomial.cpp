#include <vector>
#include <iostream>
#include <complex>

template <typename T>
class Polynomial {
public:
    std::vector<T> polynomial;
    size_t max_degree;

    Polynomial(const std::vector<T>& pol): polynomial(pol) {
        max_degree = polynomial.size() - 1;
    }

    Polynomial(const T& value = T{0}) {
        polynomial = std::vector<T>(1, value);
        max_degree = -1;
    }

    Polynomial(const Polynomial<T>& other) = default;

    Polynomial(const Polynomial<T>&& other) = default;

    template<typename Iter>
    Polynomial(Iter begin, Iter end) {
        while (begin != end) {
            polynomial.push_back(*begin);
            ++begin;
        }
        max_degree = polynomial.size() - 1;
    }

    const T& operator[](size_t degree) const {
        if (degree > max_degree)
            return polynomial[0];
        return polynomial[degree];
    }

    T& operator[](size_t degree) {
        if (degree > max_degree)
            return polynomial[0];
        return polynomial[degree];
    }

    size_t Degree() const {
        return max_degree;
    }

    T& operator()(const T& point) const {
        T res = polynomial[0];
        if (max_degree == - 1)
            return res;

        for (size_t i = 1; i < polynomial.size(); ++i) {
            res *= std::pow(point, i);
        }
        return res;
    }

    std::bidirectional_iterator_tag begin() const {
        return polynomial.begin();
    }

    std::bidirectional_iterator_tag end() const {
        return polynomial.end();
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
    return a.max_degree == -1 && a.polynomial[0] == scalar;
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
    size_t max_size = std::max(a.polynomial.size(), b.polynomial.size());
    a.polynomial.resize(max_size);
    b.polynomial.resize(max_size);
    for (size_t i = 0; i < max_size; ++i) {
        a[i] += b[i];
    }

    a.max_degree = max_size;
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
    size_t max_size = std::max(a.polynomial.size(), b.polynomial.size());
    a.polynomial.resize(max_size);
    b.polynomial.resize(max_size);
    for (size_t i = 0; i < max_size; ++i) {
        a[i] -= b[i];
    }
    a.max_degree = max_size;
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
    return a - scalar;
}

template <typename T>
Polynomial<T>& operator*=(Polynomial<T>& a, const Polynomial<T>& b) {
    size_t polynom_size = a.polynomial.size() + b.polynomial.size();
    a.polynomial.resize(polynom_size);
    for (size_t i = 0; i < a.polynomial.size(); ++i) {
        for (size_t j = 0; j < b.polynomial.size(); ++j) {
            a[i + j] += a[i] * b[i];
        }
    }
    a.max_degree = polynom_size;
    return a;
}
template <typename T>
Polynomial<T>& operator*=(Polynomial<T>& a, const T& scalar) {
    for (size_t i = 0; i < a.polynomial.size(); ++i) {
        a[i] *= scalar;
    }
}

template <typename T>
Polynomial<T> operator*(const Polynomial<T>& a, const Polynomial<T>& b) {
    auto tmp(a);
    a *= b;
    return tmp;
}

template <typename T>
Polynomial<T> operator*(const Polynomial<T>& a, const T& scalar) {
    auto tmp(a);
    a *= scalar;
    return tmp;
}

template <typename T>
Polynomial<T> operator*(const T& scalar, const Polynomial<T>& a) {
    return a * scalar;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Polynomial<T>& polynomial) {
    for (int i = polynomial.polynomial.size() - 1; i != -1; --i) {
        out << polynomial.polynomial[i] << ' ';
    }
    return out;
}

int main( ) {
    std::vector<int> pol1 = {1, 1, 2, 3};
    std::vector<int> pol2 = {2, 0, 2, 4, 5};
    Polynomial polynomial1(pol1);
    Polynomial polynomial2(pol2);
    std::cout << polynomial1 << std::endl;
    std::cout << polynomial2 << std::endl;

}
