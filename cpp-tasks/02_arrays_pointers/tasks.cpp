#include <iostream>
#include <climits>
using namespace std;


void task03() {
    int arr[] = {4, 17, 2, 9, 31, 6, 14};
    int size = 7;
    int maxEl = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > maxEl) maxEl = arr[i];
    cout << "Максимум: " << maxEl << endl;
}


void task05() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    for (int i = 0; i < size / 2; i++)
        swap(arr[i], arr[size - 1 - i]);
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}


void task10() {
    int arr[] = {3, 14, 7, 22, 8, 1};
    int size = 6;
    int max1 = INT_MIN, max2 = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max1) { max2 = max1; max1 = arr[i]; }
        else if (arr[i] > max2 && arr[i] != max1) max2 = arr[i];
    }
    cout << "Второй по величине: " << max2 << endl;
}


void task19() {
    int arr[] = {2, 7, 4, 1, 5, 9};
    int size = 6, target = 9;
    cout << "Пары с суммой " << target << ":" << endl;
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            if (arr[i] + arr[j] == target)
                cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
}


void doubleValue(int* p) { *p *= 2; }

void task27() {
    int x = 10;
    doubleValue(&x);
    cout << "После удвоения: " << x << endl;
}


int* findElement(int* arr, int size, int target) {
    for (int i = 0; i < size; i++)
        if (arr[i] == target) return &arr[i];
    return nullptr;
}

void task30() {
    int arr[] = {5, 12, 3, 8, 19, 7};
    int* found = findElement(arr, 6, 8);
    if (found) cout << "Найдено: " << *found << endl;
    else cout << "Не найдено" << endl;
}


void addTax(double& price, double rate) { price *= (1 + rate / 100); }

void task42() {
    double price = 1000.0;
    addTax(price, 20.0);
    cout << "После НДС 20%: " << price << endl;
}


void swapRef(int& a, int& b) { int tmp = a; a = b; b = tmp; }

void task45() {
    int x = 5, y = 99;
    swapRef(x, y);
    cout << "x=" << x << " y=" << y << endl;
}


void task61() {
    int rows = 3, cols = 4;
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++)
            matrix[i][j] = i * cols + j + 1;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cout << matrix[i][j] << "\t";
        cout << endl;
    }
    for (int i = 0; i < rows; i++) delete[] matrix[i];
    delete[] matrix;
}


template<typename T>
class UniquePtr {
    T* ptr;
public:
    explicit UniquePtr(T* p = nullptr) : ptr(p) {}
    ~UniquePtr() { delete ptr; }
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    T* get() const { return ptr; }
};

void task75() {
    UniquePtr<int> p(new int(42));
    cout << "UniquePtr значение: " << *p << endl;
}


int main() {
    cout << "=== Задача 03 ===" << endl; task03();
    cout << "=== Задача 05 ===" << endl; task05();
    cout << "=== Задача 10 ===" << endl; task10();
    cout << "=== Задача 19 ===" << endl; task19();
    cout << "=== Задача 27 ===" << endl; task27();
    cout << "=== Задача 30 ===" << endl; task30();
    cout << "=== Задача 42 ===" << endl; task42();
    cout << "=== Задача 45 ===" << endl; task45();
    cout << "=== Задача 61 ===" << endl; task61();
    cout << "=== Задача 75 ===" << endl; task75();
    return 0;
}
