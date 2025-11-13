#include "ArrayProcessor.hpp"
#include <iostream>

int main() {
    std::cout << "Тип данных: int" << std::endl;
    ArrayProcessor<int> intProcessor(-10, 10, 15);
    intProcessor.processAll();

    std::cout << "Тип данных: double" << std::endl;
    ArrayProcessor<double> doubleProcessor(-10.0, 10.0, 12);
    doubleProcessor.processAll();

    std::cout << "Тип данных: float" << std::endl;
    ArrayProcessor<float> floatProcessor(-10.0f, 10.0f, 10);
    floatProcessor.processAll();

    return 0;
}
