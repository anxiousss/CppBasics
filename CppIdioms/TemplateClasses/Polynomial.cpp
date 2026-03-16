#include <vector>


template <typename T>
class Polynomial {
public:
    std::vector<T> polynomial;

    Polynomial(const std::vector<T>& pol): polynomial(pol) {}

    Polynomial() {
        polynomial = std::vector<T>(1);
    }

    template<typename Iter>
    Polynomial(Iter begin, Iter end) {
        while (begin != end) {
            polynomial.push_back(*begin);
            ++begin;
        }
    }

};

template <typename T>
bool operator==(const Polynomial<T>& a, const Polynomial<T>& b) {
    for (size_t i = 0; i < a.polynomial.size(); ++i) {
        if (a.polynomial[i] != b.polynomial[i])
            return false;
    }
    return true;
}

template <typename T>
bool operator==(const Polynomial<T>& a, const T& scalar) {
    return a.polynomial[a.polynomial.size() - 1] = scalar;
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
Polynomial<T>& operator+=(Polynomial<T>& a, const Polynomial<T>& b) {
    for (size_t i = 0; i < a.polynomial.size(); ++i) {
        a[i] += b[i];
    }
    return a;
}

template <typename T>
Polynomial<T> operator+(const Polynomial<T>& a, const Polynomial<T>& b) {

}