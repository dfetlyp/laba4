#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <set>

template<typename T>
void mySwap(T& a, T& b) {
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

template<typename Container>
std::string conteiner_to_string(const Container& c) {
    std::ostringstream oss;
    for (const auto& el : c) {
        oss << el << " ";
    }
    return oss.str();
}

void testMySwap() {
    int a = 1, b = 2;
    mySwap(a, b);
    std::cout << "After mySwap: a=" << a << ", b=" << b << '\n';

    std::string aa = "first", bb = "second";
    mySwap(aa, bb);
    std::cout << "After mySwap: a=" << aa << ", b=" << bb << '\n';
    
    double aaa = 1.11, bbb = 2.22;
    mySwap(aaa, bbb);
    std::cout << "After mySwap: a=" << aaa << ", b=" << bbb << '\n';
}

void testContainerToString() {
    std::vector<int> v = { 1, 2, 3 };
    std::list<std::string> l = { "a", "b", "c" };
    std::set<double> s = { 1.1, 2.2 };

    std::cout << "Vector: " << conteiner_to_string(v) << '\n';
    std::cout << "List: " << conteiner_to_string(l) << '\n';
    std::cout << "Set: " << conteiner_to_string(s) << '\n';
}
