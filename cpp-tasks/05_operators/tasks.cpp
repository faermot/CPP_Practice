#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <stdexcept>
#include <string>
using namespace std;


class Fraction {
    long long n, d;
    void normalize() {
        if (d < 0) { d = -d; n = -n; }
        long long g = gcd(abs(n), d);
        n /= g; d /= g;
    }
public:
    Fraction(long long num = 0, long long den = 1) : n(num), d(den) { normalize(); }

    Fraction& operator+=(const Fraction& o) { n = n*o.d + o.n*d; d *= o.d; normalize(); return *this; }
    Fraction& operator-=(const Fraction& o) { n = n*o.d - o.n*d; d *= o.d; normalize(); return *this; }

    friend Fraction operator+(Fraction l, const Fraction& r) { return l += r; }
    friend Fraction operator-(Fraction l, const Fraction& r) { return l -= r; }
    friend Fraction operator*(const Fraction& a, const Fraction& b) { return {a.n*b.n, a.d*b.d}; }
    friend Fraction operator/(const Fraction& a, const Fraction& b) { return {a.n*b.d, a.d*b.n}; }
    friend Fraction operator+(long long v, const Fraction& f) { return Fraction(v) + f; }
    friend Fraction operator+(const Fraction& f, long long v) { return f + Fraction(v); }

    bool operator==(const Fraction& o) const { return n == o.n && d == o.d; }
    bool operator!=(const Fraction& o) const { return !(*this == o); }
    bool operator<(const Fraction& o) const { return n * o.d < o.n * d; }
    bool operator>(const Fraction& o) const { return o < *this; }
    Fraction operator+() const { return *this; }
    Fraction operator-() const { return {-n, d}; }

    friend ostream& operator<<(ostream& os, const Fraction& f) { return os << f.n << "/" << f.d; }
    friend istream& operator>>(istream& is, Fraction& f) { char slash; is >> f.n >> slash >> f.d; f.normalize(); return is; }
};


class Complex {
    double r, i;
public:
    Complex(double r = 0, double i = 0) : r(r), i(i) {}

    Complex operator+(const Complex& o) const { return {r + o.r, i + o.i}; }
    Complex operator-(const Complex& o) const { return {r - o.r, i - o.i}; }
    Complex operator*(const Complex& o) const { return {r*o.r - i*o.i, r*o.i + i*o.r}; }
    Complex operator-() const { return {-r, -i}; }
    bool operator==(const Complex& o) const { return r == o.r && i == o.i; }

    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.r;
        if (c.i >= 0) os << "+";
        return os << c.i << "i";
    }
};


class Vector2D {
public:
    double x, y;
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    Vector2D& operator+=(const Vector2D& o) { x += o.x; y += o.y; return *this; }
    Vector2D& operator-=(const Vector2D& o) { x -= o.x; y -= o.y; return *this; }

    friend Vector2D operator+(Vector2D l, const Vector2D& r) { return l += r; }
    friend Vector2D operator-(Vector2D l, const Vector2D& r) { return l -= r; }
    friend Vector2D operator*(const Vector2D& v, double k) { return {v.x*k, v.y*k}; }
    friend Vector2D operator*(double k, const Vector2D& v) { return v * k; }
    Vector2D operator-() const { return {-x, -y}; }

    friend ostream& operator<<(ostream& os, const Vector2D& v) { return os << "(" << v.x << ", " << v.y << ")"; }
};


class Counter {
    int value;
public:
    Counter(int v = 0) : value(v) {}
    Counter& operator++() { ++value; return *this; }
    Counter operator++(int) { Counter old = *this; ++(*this); return old; }
    Counter& operator--() { --value; return *this; }
    Counter operator--(int) { Counter old = *this; --(*this); return old; }
    int get() const { return value; }
};


class IntArray {
    int* data;
    int n;
public:
    IntArray(int size) : n(size), data(new int[size]{}) {}
    ~IntArray() { delete[] data; }

    int& operator[](int i) {
        if (i < 0 || i >= n) throw out_of_range("index out of range");
        return data[i];
    }
    const int& operator[](int i) const {
        if (i < 0 || i >= n) throw out_of_range("index out of range");
        return data[i];
    }
    int size() const { return n; }
};


class Matrix {
    int rows, cols;
    vector<double> data;
public:
    Matrix(int r, int c) : rows(r), cols(c), data(r*c, 0.0) {}

    double& operator()(int r, int c) { return data[r * cols + c]; }
    double  operator()(int r, int c) const { return data[r * cols + c]; }

    Matrix operator+(const Matrix& o) const {
        Matrix res(rows, cols);
        for (int i = 0; i < rows*cols; i++) res.data[i] = data[i] + o.data[i];
        return res;
    }
    bool operator==(const Matrix& o) const { return rows == o.rows && cols == o.cols && data == o.data; }

    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) cout << (*this)(i, j) << "\t";
            cout << "\n";
        }
    }
};


class Logger {
    string prefix;
public:
    Logger(const string& p = "[LOG]") : prefix(p) {}
    void operator()(const string& msg) const { cout << prefix << " " << msg << "\n"; }
    void operator()(const string& msg, int level) const { cout << prefix << "[" << level << "] " << msg << "\n"; }
};


class Handle {
    bool valid;
public:
    Handle(bool v = true) : valid(v) {}
    bool operator!() const { return !valid; }
    explicit operator bool() const { return valid; }
};


class StringBuilder {
    string data;
public:
    StringBuilder& operator+=(const string& s) { data += s; return *this; }
    friend StringBuilder operator+(StringBuilder l, const string& r) { l += r; return l; }
    friend ostream& operator<<(ostream& os, const StringBuilder& sb) { return os << sb.data; }
};


int main() {
    Fraction a(1, 2), b(1, 3);
    cout << a + b << "  " << a - b << "  " << a * b << "  " << a / b << "\n";
    cout << (2 + a) << "  " << (a + 3) << "\n";
    cout << -a << "  " << +a << "\n";
    cout << (a < b ? "a<b" : "a>=b") << "\n";

    Complex c1(3, 4), c2(1, -2);
    cout << c1 + c2 << "  " << c1 * c2 << "  " << -c1 << "\n";

    Vector2D v1(1, 2), v2(3, 4);
    cout << v1 + v2 << "  " << v1 - v2 << "\n";
    cout << v1 * 3.0 << "  " << 2.0 * v2 << "\n";
    v1 += v2;
    cout << v1 << "\n";

    Counter c(5);
    cout << (++c).get() << "  " << (c++).get() << "  " << c.get() << "\n";
    cout << (--c).get() << "\n";

    IntArray arr(5);
    arr[0] = 10; arr[1] = 20; arr[2] = 30;
    for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
    cout << "\n";
    try { arr[10]; } catch (const out_of_range& e) { cout << "Ошибка: " << e.what() << "\n"; }

    Matrix m(3, 3);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) m(i, j) = i*3 + j + 1;
    m.print();

    Logger log, errLog("[ERROR]");
    log("Запущено");
    log("Уровень 2", 2);
    errLog("Ошибка!");

    Handle h1(true), h2(false);
    cout << (bool)h1 << "  " << !h2 << "\n";

    StringBuilder sb;
    sb += "Hello"; sb += ", "; sb += "World!";
    cout << sb << "\n";

    return 0;
}
