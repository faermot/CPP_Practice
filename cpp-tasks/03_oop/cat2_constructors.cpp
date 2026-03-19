#include <iostream>
#include <string>
using namespace std;

class Point {
public:
    int x, y;
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
    void print() const { cout << "(" << x << ", " << y << ")" << endl; }
};

class Rectangle {
public:
    double width, height;
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const { return width * height; }
};

class Array {
    int* data;
    int size;
public:
    Array(int n) : size(n), data(new int[n]) {}
    ~Array() { delete[] data; }
    int getSize() const { return size; }
};

class Complex {
public:
    double real, imag;
    Complex() : real(0), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}
};

class Student {
    string name;
    int age;
public:
    Student(const string& n, int a) : name(n), age(a) {}
    ~Student() { cout << name << " удалён" << endl; }
    void print() const { cout << name << ", " << age << endl; }
};

class BankAccount {
    double balance;
public:
    BankAccount() : balance(0.0) {}
    BankAccount(double initial) : balance(initial) {}
    BankAccount(const BankAccount& other) : balance(other.balance) {}
    double getBalance() const { return balance; }
};

class Circle {
    double radius;
public:
    explicit Circle(double r) : radius(r) {}
    double area() const { return 3.14159 * radius * radius; }
};

class Date {
    int day, month, year;
public:
    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}
    void print() const { cout << day << "." << month << "." << year << endl; }
};

class Money {
    int rubles, kopecks;
public:
    Money() : rubles(0), kopecks(0) {}
    Money(int r) : Money(r, 0) {}
    Money(int r, int k) : rubles(r), kopecks(k) {}
    void print() const { cout << rubles << " руб. " << kopecks << " коп." << endl; }
};

int main() {
    Point p1, p2(3, 7);
    p1.print(); p2.print();

    Rectangle rect(5.0, 3.0);
    cout << "Площадь: " << rect.area() << endl;

    {
        Student s("Иван", 20);
        s.print();
    }

    BankAccount acc1, acc2(1000.0), acc3(acc2);
    cout << "Баланс: " << acc3.getBalance() << endl;

    Circle c(5.0);
    cout << "Площадь круга: " << c.area() << endl;

    Date d(15, 6, 2024);
    d.print();

    Money m1, m2(100), m3(50, 75);
    m3.print();

    return 0;
}
