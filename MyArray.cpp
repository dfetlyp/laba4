#include <iostream>
#include <string>

template<typename T, size_t N>
class MyArray {
    T data[N];

public:
    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }

    size_t size() const {
        return N;
    }
};

void testMyArray() {
    MyArray<std::string, 5> arr;
  
    arr[0] = "one";
    arr[1] = "two";
    arr[2] = "three";
    arr[3] = "four";
    arr[4] = "five";
 
    std::cout << "MyArray contents:\n";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << ' ';
    }

    MyArray<int, 4> arr2;

    arr2[0] = 1;
    arr2[1] = 2;
    arr2[2] = 3;
    arr2[3] = 4;

    std::cout << "\nMyArray2 contents:\n";
    for (size_t i = 0; i < arr2.size(); ++i) {
        std::cout << arr2[i] << ' ';
    }

    MyArray<double, 4> arr3;

    arr3[0] = 1.1;
    arr3[1] = 2.2;
    arr3[2] = 3.3;
    arr3[3] = 4.4;

    std::cout << "\nMyArray3 contents:\n";
    for (size_t i = 0; i < arr3.size(); ++i) {
        std::cout << arr3[i] << ' ';
    }
}
