#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;


int max(int a, int b) { return a > b ? a : b; }
double max(double a, double b) { return a > b ? a : b; }
char max(char a, char b) { return a > b ? a : b; }


double area(double radius) { return 3.14159 * radius * radius; }
double area(double w, double h) { return w * h; }
double area(double base, double height, bool) { return 0.5 * base * height; }


long long pow(int base, int exp) {
    long long r = 1;
    for (int i = 0; i < exp; i++) r *= base;
    return r;
}
double pow(double base, int exp) {
    double r = 1.0;
    for (int i = 0; i < exp; i++) r *= base;
    return r;
}


void print(const string& s) { cout << s << '\n'; }
void print(int x) { cout << x << '\n'; }
void print(double x) { cout << x << '\n'; }


int min(int a, int b, int c) { return a < b ? (a < c ? a : c) : (b < c ? b : c); }
double min(double a, double b, double c) { return a < b ? (a < c ? a : c) : (b < c ? b : c); }


void drawRectangle(int width, int height, char ch = '#') {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) cout << ch;
        cout << '\n';
    }
}

double power(double base, int exp = 2) {
    double r = 1.0;
    for (int i = 0; i < exp; i++) r *= base;
    return r;
}

string greet(const string& name = "Guest", const string& prefix = "Hello") {
    return prefix + ", " + name + "!";
}

void drawLine(int length, char ch = '-', bool newline = true) {
    for (int i = 0; i < length; i++) cout << ch;
    if (newline) cout << '\n';
}

void sortArray(int* arr, int size, bool ascending = true) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - 1 - i; j++) {
            bool needSwap = ascending ? arr[j] > arr[j+1] : arr[j] < arr[j+1];
            if (needSwap) swap(arr[j], arr[j+1]);
        }
}

bool saveSettings(const string& path = "config.ini", bool overwrite = false) {
    ios_base::openmode mode = ios::out;
    if (!overwrite) mode |= ios::app;
    ofstream file(path, mode);
    if (!file) return false;
    file << "volume=80\nbrightness=50\n";
    return true;
}


class IntArray {
    int* data;
    int size;
public:
    IntArray(int n) : size(n), data(new int[n]) {
        for (int i = 0; i < n; i++) data[i] = 0;
    }
    IntArray(const IntArray& other) : size(other.size), data(new int[other.size]) {
        for (int i = 0; i < size; i++) data[i] = other.data[i];
    }
    ~IntArray() { delete[] data; }
    void set(int i, int v) { if (i >= 0 && i < size) data[i] = v; }
    int get(int i) const { return data[i]; }
    int getSize() const { return size; }
};

class PointXY {
public:
    int x, y;
    PointXY() : x(0), y(0) {}
    PointXY(int x) : x(x), y(0) {}
    PointXY(int x, int y) : x(x), y(y) {}
    PointXY(const PointXY& o) : x(o.x), y(o.y) {}
    void print() const { cout << "(" << x << ", " << y << ")\n"; }
};

class Person {
    string name;
    int age;
public:
    Person(const string& n = "Unknown", int a = 0) : name(n), age(a) {}
    Person(const Person& o) : name(o.name), age(o.age) {
        cout << "Copied: " << name << "\n";
    }
    void print() const { cout << name << ", " << age << "\n"; }
};

class Vector2D {
public:
    double x, y;
    Vector2D() : x(0), y(0) {}
    Vector2D(double x, double y) : x(x), y(y) {}
    Vector2D(const Vector2D& o) : x(o.x), y(o.y) {}
    double length() const { return sqrt(x*x + y*y); }
    void print() const { cout << "(" << x << ", " << y << ")\n"; }
};

struct Point2 { double x, y; };

class RectangleFull {
    double width, height;
public:
    RectangleFull() : width(0), height(0) {}
    RectangleFull(double w, double h) : width(w), height(h) {}
    RectangleFull(Point2 p1, Point2 p2) : width(abs(p2.x - p1.x)), height(abs(p2.y - p1.y)) {}
    RectangleFull(const RectangleFull& o) : width(o.width), height(o.height) {}
    double area() const { return width * height; }
    void print() const { cout << width << " x " << height << "\n"; }
};

int main() {
    cout << max(3, 7) << "\n";
    cout << max(3.14, 2.71) << "\n";
    cout << max('a', 'z') << "\n";

    cout << area(5.0) << "\n";
    cout << area(4.0, 6.0) << "\n";
    cout << area(3.0, 8.0, true) << "\n";

    cout << pow(2, 10) << "\n";
    cout << pow(2.5, 3) << "\n";

    print(string("hello")); print(42); print(3.14);

    drawRectangle(5, 3);
    drawRectangle(4, 2, '*');

    cout << power(5.0) << "\n";
    cout << power(3.0, 4) << "\n";

    cout << greet() << "\n";
    cout << greet("Иван", "Привет") << "\n";

    drawLine(10);
    drawLine(8, '=');

    int arr[] = {5, 1, 4, 2, 8};
    sortArray(arr, 5);
    for (int x : arr) cout << x << " "; cout << "\n";
    sortArray(arr, 5, false);
    for (int x : arr) cout << x << " "; cout << "\n";

    IntArray a(5);
    a.set(0, 10); a.set(1, 20);
    IntArray b = a;
    b.set(0, 99);
    cout << a.get(0) << " " << b.get(0) << "\n";

    PointXY p1, p2(5), p3(3, 7), p4 = p3;
    p1.print(); p2.print(); p3.print(); p4.print();

    Person per1("Анна", 22);
    Person per2 = per1;
    per1.print(); per2.print();

    Vector2D v(3.0, 4.0);
    Vector2D v2 = v;
    cout << v.length() << "\n";

    RectangleFull r1, r2(5.0, 3.0), r3({0,0}, {4.0, 6.0}), r4 = r2;
    r2.print(); r3.print();

    return 0;
}
