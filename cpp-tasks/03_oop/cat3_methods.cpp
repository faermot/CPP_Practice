#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Point {
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int v) { x = v; }
    void setY(int v) { y = v; }
    void display() const { cout << "Point(" << x << ", " << y << ")" << endl; }
};

class Rectangle {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const { return width * height; }
    double perimeter() const { return 2 * (width + height); }
    void resize(double factor) { width *= factor; height *= factor; }
    void display() const { cout << width << " x " << height << endl; }
};

class Circle {
    double radius;
    static const double PI;
public:
    Circle(double r) : radius(r) {}
    void setRadius(double r) { radius = r; }
    double getRadius() const { return radius; }
    double area() const { return PI * radius * radius; }
    double circumference() const { return 2 * PI * radius; }
};
const double Circle::PI = 3.14159265358979;

class Student {
    string name;
    int age;
public:
    Student(const string& n, int a) : name(n), age(a) {}
    void display() const { cout << "Студент: " << name << ", " << age << " лет" << endl; }
    string toString() const { return name + ", " + to_string(age); }
    int compare(const Student& other) const { return name.compare(other.name); }
};

class Stack {
    int data[100];
    int top;
public:
    Stack() : top(-1) {}
    void push(int val) { if (top < 99) data[++top] = val; }
    int pop() { return top >= 0 ? data[top--] : -1; }
    int peek() const { return top >= 0 ? data[top] : -1; }
    bool isEmpty() const { return top == -1; }
    int length() const { return top + 1; }
    void clear() { top = -1; }
};

class Counter {
    int count;
public:
    Counter() : count(0) {}
    void increment() { count++; }
    void decrement() { if (count > 0) count--; }
    void reset() { count = 0; }
    int getCount() const { return count; }
};

int main() {
    Point p(3, 5);
    p.display();
    cout << "X: " << p.getX() << endl;

    Rectangle r(4.0, 6.0);
    cout << "Площадь: " << r.area() << " Периметр: " << r.perimeter() << endl;
    r.resize(2.0);
    r.display();

    Circle c(5.0);
    cout << "Площадь круга: " << c.area() << endl;

    Stack s;
    s.push(10); s.push(20); s.push(30);
    cout << "Вершина: " << s.peek() << endl;
    cout << "Pop: " << s.pop() << endl;
    cout << "Размер: " << s.length() << endl;

    Counter cnt;
    cnt.increment(); cnt.increment(); cnt.increment();
    cout << "Счётчик: " << cnt.getCount() << endl;
    cnt.decrement();
    cout << "После декремента: " << cnt.getCount() << endl;

    return 0;
}
