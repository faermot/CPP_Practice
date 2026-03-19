#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cout << "Введите три стороны: ";
    cin >> a >> b >> c;

    if (a + b <= c || a + c <= b || b + c <= a) {
        cout << "Треугольник не существует" << endl;
        return 0;
    }
    cout << "Треугольник существует" << endl;

    double sides[3] = {a, b, c};
    for (int i = 0; i < 2; i++)
        for (int j = i + 1; j < 3; j++)
            if (sides[i] > sides[j]) swap(sides[i], sides[j]);

    if (abs(sides[0]*sides[0] + sides[1]*sides[1] - sides[2]*sides[2]) < 1e-9)
        cout << "Прямоугольный" << endl;
    else if (a == b && b == c)
        cout << "Равносторонний" << endl;
    else if (a == b || b == c || a == c)
        cout << "Равнобедренный" << endl;
    else
        cout << "Разносторонний" << endl;

    return 0;
}
