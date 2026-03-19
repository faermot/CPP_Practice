#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int secret = rand() % 100 + 1;
    int guess, attempts = 0;

    cout << "Угадайте число от 1 до 100!" << endl;

    do {
        cout << "Ваш ответ: ";
        cin >> guess;
        attempts++;

        if (guess < secret) cout << "Больше!" << endl;
        else if (guess > secret) cout << "Меньше!" << endl;
        else cout << "Правильно! Попыток: " << attempts << endl;
    } while (guess != secret);

    return 0;
}
