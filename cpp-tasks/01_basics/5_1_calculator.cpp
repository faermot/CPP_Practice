#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b;
    char op;
    cout << "Введите: число оператор число: ";
    cin >> a >> op >> b;

    switch (op) {
        case '+': cout << "= " << a + b << endl; break;
        case '-': cout << "= " << a - b << endl; break;
        case '*': cout << "= " << a * b << endl; break;
        case '/':
            if (b == 0) cout << "Ошибка: деление на ноль" << endl;
            else cout << "= " << a / b << endl;
            break;
        case '^': cout << "= " << pow(a, b) << endl; break;
        case '%':
            if ((int)b == 0) cout << "Ошибка: деление на ноль" << endl;
            else cout << "= " << (int)a % (int)b << endl;
            break;
        default: cout << "Неизвестная операция" << endl;
    }

    return 0;
}
