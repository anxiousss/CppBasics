#include <numeric>
#include <iostream>

class Rational {
private:
    void reduction() {
        if (this->denominator < 0) {
            this->numerator *= -1;
            this->denominator *= -1;
        }
        int x = std::gcd(this->denominator, this->numerator);
        this->numerator /= x;
        this->denominator /= x;
    }
public:

    int numerator;
    int denominator;
    Rational(int num = 0, int denom = 1) {
        this->numerator = num;
        this->denominator = denom;
        this->reduction();
    }

    int Numerator() const {
        return this->numerator;
    }

    int Denominator() const{
        return this->denominator;
    }

    Rational operator+(const Rational& other) const {
        int new_numerator = other.numerator * this->denominator + this->numerator * other.denominator;
        int new_denominator = this->denominator * other.denominator;
        return {new_numerator, new_denominator};
    }

    Rational operator+(const int other) const {
        int new_numerator = other * this->denominator + this->numerator;
        return {new_numerator, this->denominator};
    }

    Rational operator+() const {
        return {this->numerator, this->denominator};
    }

    friend Rational operator+(int left, const Rational& right) {
        return right + left;
    }

    Rational operator-(const Rational& other) const {
        int new_numerator = this->numerator * other.denominator - this->denominator * other.numerator;
        int new_denominator = this->denominator * other.denominator;
        return {new_numerator, new_denominator};
    }

    Rational operator-(const int other) const {
        int new_numerator = this->numerator - other * this->denominator;
        return {new_numerator, this->denominator};
    }

    friend Rational operator-(const int left, const Rational& right) {
        return left + (-right);
    }

    Rational operator-() const {
        return {-this->numerator, this->denominator};
    }

    Rational operator*(const Rational& other) const {
        int new_numerator = this->numerator * other.numerator;
        int new_denominator = this->denominator * other.denominator;
        return {new_numerator, new_denominator};
    }

    Rational operator*(const int other) const {
        int new_numerator = this->numerator * other;
        return {new_numerator, this->denominator};
    }

    friend Rational operator*(const int left, const Rational& right) {
        return right * left;
    }

    Rational operator/(const Rational& other) const {
        int new_numerator = this->numerator * other.denominator;
        int new_denominator = this->denominator * other.numerator;
        return {new_numerator, new_denominator};
    }

    Rational operator/(const int other) const {
        int new_denominator = this->denominator * other;
        return {this->numerator, new_denominator};
    }

    void operator+=(const Rational& other) {
        *this = *this + other;
        this->reduction();
    }

    void operator+=(const int other) {
        *this = *this + other;
        this->reduction();
    }

    void operator -=(const Rational& other) {
        *this = *this - other;
        this->reduction();
    }

    void operator-=(const int other) {
        *this = *this - other;
        this->reduction();
    }

    void operator*=(const Rational& other) {
        *this = *this * other;
        this->reduction();
    }

    void operator*=(const int other) {
        *this = *this * other;
        this->reduction();
    }

    void operator/=(const Rational& other) {
        *this = *this / other;
        this->reduction();
    }

    void operator/=(const int other) {
        *this = *this / other;
        this->reduction();
    }

    bool operator==(const Rational& other) const {
        return this->numerator * other.denominator == this->denominator * other.numerator;
    }

    bool operator==(const int other) const {
        return this->numerator / this->denominator == other;
    }

    bool operator!=(const Rational& other) const {
        return !(*this == other);
    }

    bool operator!=(const int other)const {
        return !(*this == other);
    }
};
