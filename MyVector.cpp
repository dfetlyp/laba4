#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std::chrono;


class MyVector {
    int* data;
    size_t size;

public:
    // конструктор 
    MyVector(size_t n) : size(n) {
        data = new int[n] {}; // выделение памяти, заполняется нулями
        std::cout << "constructor" << std::endl;
    }
    // деструктор
    ~MyVector() {
        delete[] data;
        std::cout << "destructor" << std::endl;
    }
    // копи контруктор
    // создание нового объекта как копии существующего
    // память выделяется заново
    MyVector(const MyVector& other) : size(other.size) {
        data = new int[size];
        std::copy(other.data, other.data + size, data);
        std::cout << "copy constructor" << std::endl;
    }
    // копи оператор присваивания
    // старые данные удаляются, копируется новая информация.
    MyVector& operator=(const MyVector& other) {
        // проверка на самоприсваивание
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            std::copy(other.data, other.data + size, data);
        }
        return *this;
    }
    // мув конструктор
    // перемещение без копирования
    MyVector(MyVector&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        std::cout << "move constructor" << std::endl;
    }
    // мув оператор присваивания
    MyVector& operator=(MyVector&& other) noexcept {
        // проверка на самоприсваивание
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }
};

void testMyVector() {
    MyVector a(10000000);
    auto start = high_resolution_clock::now();
    MyVector b = a;
    auto end = high_resolution_clock::now();
    std::cout << "copy time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";

    start = high_resolution_clock::now();
    MyVector c = std::move(a);
    end = high_resolution_clock::now();
    std::cout << "move time: " << duration_cast<milliseconds>(end - start).count() << " ms\n";
}
