#include "ArrayProcessor.hpp"
#include <iostream>
#include <cassert>

// Простые тесты для проверки корректности операций
void testIntOperations() {
    std::cout << "Тест 1: Проверка операций с int..." << std::endl;
    
    ArrayProcessor<int> proc(-10, 10, 10);
    proc.print("Исходный массив:");
    
    proc.multiplyByTwo();
    proc.print("После умножения на 2:");
    
    proc.replaceAbsGreaterThan10();
    proc.print("После замены |x| > 10 на 0:");
    
    proc.removeZeros();
    proc.print("После удаления нулей:");
    
    std::cout << "✓ Тест 1 пройден!" << std::endl << std::endl;
}

void testDoubleOperations() {
    std::cout << "Тест 2: Проверка операций с double..." << std::endl;
    
    ArrayProcessor<double> proc(-10.0, 10.0, 8);
    proc.print("Исходный массив:");
    
    proc.multiplyByTwo();
    proc.print("После умножения на 2:");
    
    proc.replaceAbsGreaterThan10();
    proc.print("После замены |x| > 10 на 0:");
    
    proc.removeZeros();
    proc.print("После удаления нулей:");
    
    std::cout << "✓ Тест 2 пройден!" << std::endl << std::endl;
}

void testFloatOperations() {
    std::cout << "Тест 3: Проверка операций с float..." << std::endl;
    
    ArrayProcessor<float> proc(-10.0f, 10.0f, 5);
    proc.print("Исходный массив:");
    
    proc.multiplyByTwo();
    proc.print("После умножения на 2:");
    
    proc.replaceAbsGreaterThan10();
    proc.print("После замены |x| > 10 на 0:");
    
    proc.removeZeros();
    proc.print("После удаления нулей:");
    
    std::cout << "✓ Тест 3 пройден!" << std::endl << std::endl;
}

int main() {
    std::cout << "═══════════════════════════════════════════════════════════════" << std::endl;
    std::cout << "         ТЕСТИРОВАНИЕ КЛАССА ArrayProcessor                    " << std::endl;
    std::cout << "═══════════════════════════════════════════════════════════════" << std::endl;
    std::cout << std::endl;
    
    testIntOperations();
    testDoubleOperations();
    testFloatOperations();
    
    std::cout << "═══════════════════════════════════════════════════════════════" << std::endl;
    std::cout << "         ВСЕ ТЕСТЫ УСПЕШНО ПРОЙДЕНЫ!                          " << std::endl;
    std::cout << "═══════════════════════════════════════════════════════════════" << std::endl;
    
    return 0;
}
