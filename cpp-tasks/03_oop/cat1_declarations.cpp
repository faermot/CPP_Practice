#include <iostream>
#include <string>
using namespace std;

class Point {
public:
    int x;
    int y;
};

class Rectangle {
public:
    double width;
    double height;
};

class Complex {
public:
    double real;
    double imag;
};

class Product {
public:
    string name;
    double price;
    int quantity;
};

class BankAccount {
public:
    int id;
    double balance;
};

class Student {
public:
    string name;
    int age;
};

class Car {
public:
    string brand;
    string model;
    int year;
};

class Time {
public:
    int hours;
    int minutes;
    int seconds;
};

class Date {
public:
    int day;
    int month;
    int year;
};

class Circle {
private:
    double radius;
public:
    void setRadius(double r) { radius = r; }
    double getRadius() const { return radius; }
};

int main() {
    Point p; p.x = 3; p.y = 5;
    cout << "Point: " << p.x << ", " << p.y << endl;

    Rectangle r; r.width = 4.0; r.height = 6.0;
    cout << "Rectangle: " << r.width << "x" << r.height << endl;

    Product pr; pr.name = "Книга"; pr.price = 350.0; pr.quantity = 10;
    cout << "Product: " << pr.name << " " << pr.price << endl;

    return 0;
}
