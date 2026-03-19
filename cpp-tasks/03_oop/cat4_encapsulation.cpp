#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    double balance;
    int id;
    static int nextId;
public:
    BankAccount(double initial = 0.0) : balance(initial), id(++nextId) {}

    void deposit(double amount) { if (amount > 0) balance += amount; }
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) { balance -= amount; return true; }
        return false;
    }
    double getBalance() const { return balance; }
    int getId() const { return id; }
};
int BankAccount::nextId = 0;

class Person {
    string firstName;
    string lastName;
    int age;
public:
    Person(const string& fn, const string& ln, int a)
        : firstName(fn), lastName(ln), age(0) { setAge(a); }

    void setAge(int a) { if (a >= 0 && a <= 120) age = a; }
    int getAge() const { return age; }
    string getFullName() const { return firstName + " " + lastName; }

    const string& getFirstName() const { return firstName; }
    const string& getLastName() const { return lastName; }
};

class Temperature {
    double celsius;
public:
    explicit Temperature(double c) : celsius(c) {}

    void setCelsius(double c) { celsius = c; }
    double getCelsius() const { return celsius; }
    double getFahrenheit() const { return celsius * 9.0 / 5.0 + 32; }
    double getKelvin() const { return celsius + 273.15; }
};

class Counter {
    int count;
    static int totalCreated;
public:
    Counter() : count(0) { totalCreated++; }
    void increment() { count++; }
    int getCount() const { return count; }
    static int getTotalCreated() { return totalCreated; }
};
int Counter::totalCreated = 0;

class Range {
    double minVal;
    double maxVal;
public:
    Range(double mn, double mx) : minVal(mn > mx ? mx : mn), maxVal(mn > mx ? mn : mx) {}

    double getMin() const { return minVal; }
    double getMax() const { return maxVal; }

    void setMin(double v) { if (v <= maxVal) minVal = v; }
    void setMax(double v) { if (v >= minVal) maxVal = v; }

    bool contains(double v) const { return v >= minVal && v <= maxVal; }
    double length() const { return maxVal - minVal; }
};

int main() {
    BankAccount acc(500.0);
    acc.deposit(300.0);
    acc.withdraw(100.0);
    cout << "Баланс: " << acc.getBalance() << " (ID: " << acc.getId() << ")" << endl;

    Person p("Иван", "Петров", 25);
    cout << p.getFullName() << ", " << p.getAge() << " лет" << endl;
    p.setAge(200);
    cout << "После неверного ввода: " << p.getAge() << endl;

    Temperature t(100.0);
    cout << t.getCelsius() << "C = " << t.getFahrenheit() << "F = " << t.getKelvin() << "K" << endl;

    Counter c1, c2, c3;
    c1.increment(); c1.increment();
    cout << "Создано счётчиков: " << Counter::getTotalCreated() << endl;

    Range r(1.0, 10.0);
    cout << "Содержит 5.5: " << r.contains(5.5) << endl;
    cout << "Содержит 11: " << r.contains(11) << endl;

    return 0;
}
