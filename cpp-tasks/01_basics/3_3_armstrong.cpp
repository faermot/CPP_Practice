#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Введите число: ";
    cin >> n;

    int temp = n, digits = 0;
    while (temp != 0) { digits++; temp /= 10; }

    temp = n;
    int sum = 0;
    while (temp != 0) {
        int d = temp % 10;
        sum += (int)pow(d, digits);
        temp /= 10;
    }

    if (sum == n)
        cout << n << " — число Армстронга" << endl;
    else
        cout << n << " — не число Армстронга" << endl;

    return 0;
}
