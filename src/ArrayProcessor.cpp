#include "ArrayProcessor.hpp"
#include <algorithm>
#include <random>
#include <iostream>
#include <iomanip>
#include <cmath>

template <typename T>
ArrayProcessor<T>::ArrayProcessor(T min_val, T max_val, size_t size) 
    : m1(min_val), m2(max_val) {
    
    std::random_device rd;
    std::mt19937 gen(rd());
    
    if constexpr (std::is_integral<T>::value) {
        std::uniform_int_distribution<T> dis(m1, m2);
        data.resize(size);
        std::generate(data.begin(), data.end(), [&]() { return dis(gen); });
    } else {
        std::uniform_real_distribution<T> dis(m1, m2);
        data.resize(size);
        std::generate(data.begin(), data.end(), [&]() { return dis(gen); });
    }
}

template <typename T>
void ArrayProcessor<T>::print(const std::string& message) const {
    if (!message.empty()) {
        std::cout << message << std::endl;
    }
    
    std::cout << "Массив [размер: " << data.size() << "]: ";
    
    for (const auto& elem : data) {
        std::cout << std::setw(8) << std::fixed << std::setprecision(2) << elem << " ";
    }
    std::cout << std::endl << std::endl;
}

template <typename T>
void ArrayProcessor<T>::multiplyByTwo() {
    std::transform(data.begin(), data.end(), data.begin(), 
                   [](T x) { return x * 2; });
}

template <typename T>
void ArrayProcessor<T>::replaceAbsGreaterThan10() {
    std::transform(data.begin(), data.end(), data.begin(),
                   [](T x) { 
                       return (std::abs(x) > 10) ? T(0) : x; 
                   });
}

template <typename T>
void ArrayProcessor<T>::removeZeros() {
    auto new_end = std::remove_if(data.begin(), data.end(),
                                   [](T x) { return std::abs(x) < 1e-9; });
    data.erase(new_end, data.end());
}

template <typename T>
void ArrayProcessor<T>::processAll() {
    print("Исходный массив:");
    
    multiplyByTwo();
    print("После операции 1 (умножение на 2):");
    
    replaceAbsGreaterThan10();
    print("После операции 2 (замена |x| > 10 на 0):");
    
    removeZeros();
    print("После операции 3 (удаление нулей):");
}
