#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Количество строк: ";
    cin >> n;

    int c[20][20] = {};
    for (int i = 0; i < n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = c[i-1][j-1] + c[i-1][j];
    }

    for (int i = 0; i < n; i++) {
        for (int sp = 0; sp < n - i - 1; sp++) cout << " ";
        for (int j = 0; j <= i; j++) cout << c[i][j] << " ";
        cout << endl;
    }

    return 0;
}
