#pragma once

#include <vector>
#include <string>

template <typename T>
class ArrayProcessor {
private:
    std::vector<T> data;
    T m1, m2;

public:
    ArrayProcessor(T min_val, T max_val, size_t size);
    
    void multiplyByTwo();
    void replaceAbsGreaterThan10();
    void removeZeros();
    void print(const std::string& message = "") const;
    void processAll();
};

#include "ArrayProcessor.cpp"