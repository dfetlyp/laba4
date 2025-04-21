#include <iostream>
#include <chrono> // для замера времени
#include <vector>
#include <list>
#include <set>
#include <string>

using namespace std::chrono;

// Объявления из других файлов
void testMyVector();
void testMySwap();
void testContainerToString();
void testMyArray();

int main() {
    testMyVector();
    testMySwap();
    testContainerToString();
    testMyArray();
    return 0;
}
