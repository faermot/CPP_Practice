#include <iostream>
#include <cmath>
#include <numeric>
using namespace std;

class Complex {
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& o) const { return {real + o.real, imag + o.imag}; }
    Complex operator-(const Complex& o) const { return {real - o.real, imag - o.imag}; }
    Complex operator*(const Complex& o) const {
        return {real*o.real - imag*o.imag, real*o.imag + imag*o.real};
    }
    Complex operator/(const Complex& o) const {
        double d = o.real*o.real + o.imag*o.imag;
        return {(real*o.real + imag*o.imag)/d, (imag*o.real - real*o.imag)/d};
    }
    Complex& operator+=(const Complex& o) { real += o.real; imag += o.imag; return *this; }
    Complex& operator-=(const Complex& o) { real -= o.real; imag -= o.imag; return *this; }
    Complex operator-() const { return {-real, -imag}; }
    bool operator==(const Complex& o) const { return real == o.real && imag == o.imag; }
    bool operator!=(const Complex& o) const { return !(*this == o); }

    double abs() const { return sqrt(real*real + imag*imag); }
    Complex conjugate() const { return {real, -imag}; }

    double getReal() const { return real; }
    double getImag() const { return imag; }

    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real;
        if (c.imag >= 0) os << "+";
        return os << c.imag << "i";
    }
    friend istream& operator>>(istream& is, Complex& c) {
        char plus;
        is >> c.real >> plus >> c.imag;
        return is;
    }
};

int main() {
    Complex a(3, 4), b(1, -2);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << (a + b) << endl;
    cout << "a - b = " << (a - b) << endl;
    cout << "a * b = " << (a * b) << endl;
    cout << "a / b = " << (a / b) << endl;
    cout << "|a| = " << a.abs() << endl;
    cout << "~a = " << a.conjugate() << endl;
    cout << "-a = " << (-a) << endl;
    cout << "a == b: " << (a == b) << endl;

    Complex c = a;
    c += b;
    cout << "a += b: " << c << endl;

    return 0;
}
