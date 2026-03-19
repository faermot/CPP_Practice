#include <iostream>
using namespace std;

int main() {
    int m[3][3];
    cout << "Введите матрицу 3x3 (9 чисел):" << endl;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> m[i][j];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cout << m[i][j] << "\t";
        cout << endl;
    }

    int sum = 0, maxEl = m[0][0], diagSum = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            sum += m[i][j];
            if (m[i][j] > maxEl) maxEl = m[i][j];
            if (i == j) diagSum += m[i][j];
        }

    cout << "Сумма: " << sum << endl;
    cout << "Максимум: " << maxEl << endl;
    cout << "Сумма диагонали: " << diagSum << endl;

    return 0;
}
