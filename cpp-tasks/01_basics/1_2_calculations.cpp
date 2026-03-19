#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Введите три числа: ";
    cin >> a >> b >> c;

    int sum = a + b + c;
    double avg = sum / 3.0;
    long long product = (long long)a * b * c;

    cout << "Сумма: " << sum << endl;
    cout << "Среднее: " << avg << endl;
    cout << "Произведение: " << product << endl;

    return 0;
}
