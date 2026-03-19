#include <iostream>
using namespace std;

const double PI = 3.14159;

int main() {
    double r, w, h, base, height;

    cout << "Радиус круга: ";
    cin >> r;
    cout << "Площадь круга: " << PI * r * r << endl;

    cout << "Стороны прямоугольника (w h): ";
    cin >> w >> h;
    cout << "Площадь прямоугольника: " << w * h << endl;

    cout << "Основание и высота треугольника: ";
    cin >> base >> height;
    cout << "Площадь треугольника: " << 0.5 * base * height << endl;

    return 0;
}
