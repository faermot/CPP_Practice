#include <iostream>
#include <string>
#include <cstring>
using namespace std;


class Point {
public:
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    Point operator+(const Point& o) const { return {x + o.x, y + o.y}; }
    Point operator-(const Point& o) const { return {x - o.x, y - o.y}; }
    bool operator==(const Point& o) const { return x == o.x && y == o.y; }
    bool operator!=(const Point& o) const { return !(*this == o); }
    void print() const { cout << "(" << x << ", " << y << ")" << endl; }
};

class MyString {
    char* str;
public:
    MyString(const char* s = "") {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    ~MyString() { delete[] str; }
    bool operator==(const MyString& o) const { return strcmp(str, o.str) == 0; }
    bool operator!=(const MyString& o) const { return !(*this == o); }
    void print() const { cout << str; }
};


class Circle {
    double radius;
    static int count;
    static const double PI;
public:
    Circle(double r) : radius(r) { count++; }
    ~Circle() { count--; }
    static int getCount() { return count; }
    static double getPi() { return PI; }
    double area() const { return PI * radius * radius; }
    static Circle create(double r) { return Circle(r); }
};
int Circle::count = 0;
const double Circle::PI = 3.14159265358979;


class Builder {
    int value;
public:
    Builder(int v = 0) : value(v) {}
    Builder& add(int n) { value += n; return *this; }
    Builder& multiply(int n) { value *= n; return *this; }
    Builder& subtract(int n) { value -= n; return *this; }
    int getValue() const { return value; }

    bool isEqual(const Builder& other) const { return this == &other || value == other.value; }
    Builder* clone() const { return new Builder(*this); }
};


class Vector2D {
    double x, y;
public:
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    friend double dot(const Vector2D& a, const Vector2D& b) {
        return a.x * b.x + a.y * b.y;
    }
    friend Vector2D add(const Vector2D& a, const Vector2D& b) {
        return {a.x + b.x, a.y + b.y};
    }
    friend ostream& operator<<(ostream& os, const Vector2D& v) {
        return os << "(" << v.x << ", " << v.y << ")";
    }
    friend bool operator==(const Vector2D& a, const Vector2D& b) {
        return a.x == b.x && a.y == b.y;
    }
};

int main() {
    Point p1(1, 2), p2(3, 4);
    (p1 + p2).print();
    (p2 - p1).print();
    cout << (p1 == p2 ? "равны" : "не равны") << endl;

    cout << "Кругов: " << Circle::getCount() << endl;
    { Circle c1(5), c2(3); cout << "Кругов: " << Circle::getCount() << endl; }
    cout << "Кругов: " << Circle::getCount() << endl;

    Builder b(2);
    cout << b.add(3).multiply(4).subtract(2).getValue() << endl;

    Builder* copy = b.clone();
    cout << "Клон: " << copy->getValue() << endl;
    delete copy;

    Vector2D v1(1, 2), v2(3, 4);
    cout << v1 << " dot " << v2 << " = " << dot(v1, v2) << endl;
    cout << "Сумма: " << add(v1, v2) << endl;

    return 0;
}
