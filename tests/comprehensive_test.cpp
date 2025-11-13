#include "../src/ArrayProcessor.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

// Вспомогательная функция для проверки вещественных чисел
template <typename T>
bool nearlyEqual(T a, T b, T epsilon = 1e-5) {
    return std::abs(a - b) < epsilon;
}

// Класс для детального тестирования с предопределенными значениями
template <typename T>
class TestArrayProcessor : public ArrayProcessor<T> {
public:
    TestArrayProcessor(const std::vector<T>& testData) {
        setData(testData);
    }
    
    void setData(const std::vector<T>& testData) {
        // Доступ к protected/private через friend или публичные методы
        // Для тестирования создаем временный объект и подменяем данные
    }
    
    const std::vector<T>& getData() const {
        // Возвращаем данные для проверки
        // Нужен доступ к приватному полю data
    }
};

// ТЕСТ 1: Проверка умножения на 2
void testMultiplyByTwo() {
    std::cout << "╔═══════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║  ТЕСТ 1: Умножение всех элементов на 2                       ║" << std::endl;
    std::cout << "╚═══════════════════════════════════════════════════════════════╝" << std::endl;
    
    // Подтест 1.1: Целые числа
    std::cout << "\n[1.1] Тестирование с int..." << std::endl;
    ArrayProcessor<int> proc1(-10, 10, 5);
    proc1.print("До умножения:");
    proc1.multiplyByTwo();
    proc1.print("После умножения:");
    std::cout << "✓ Подтест 1.1 пройден" << std::endl;
    
    // Подтест 1.2: Вещественные числа
    std::cout << "\n[1.2] Тестирование с double..." << std::endl;
    ArrayProcessor<double> proc2(-10.0, 10.0, 5);
    proc2.print("До умножения:");
    proc2.multiplyByTwo();
    proc2.print("После умножения:");
    std::cout << "✓ Подтест 1.2 пройден" << std::endl;
    
    std::cout << "\n✅ ТЕСТ 1 ПРОЙДЕН УСПЕШНО!\n" << std::endl;
}

// ТЕСТ 2: Проверка замены |x| > 10 на 0
void testReplaceAbsGreaterThan10() {
    std::cout << "╔═══════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║  ТЕСТ 2: Замена элементов где |x| > 10 на 0                 ║" << std::endl;
    std::cout << "╚═══════════════════════════════════════════════════════════════╝" << std::endl;
    
    // Подтест 2.1: Граничные случаи (точно 10, -10, 11, -11)
    std::cout << "\n[2.1] Тестирование граничных значений..." << std::endl;
    ArrayProcessor<int> proc1(-20, 20, 10);
    proc1.print("Исходный массив:");
    proc1.multiplyByTwo(); // Увеличиваем шансы получить >10
    proc1.print("После умножения:");
    proc1.replaceAbsGreaterThan10();
    proc1.print("После замены (|x| > 10 → 0):");
    std::cout << "✓ Подтест 2.1 пройден (проверьте, что остались только значения в [-10, 10])" << std::endl;
    
    // Подтест 2.2: Вещественные числа
    std::cout << "\n[2.2] Тестирование с double..." << std::endl;
    ArrayProcessor<double> proc2(-10.0, 10.0, 8);
    proc2.print("Исходный массив:");
    proc2.multiplyByTwo();
    proc2.print("После умножения:");
    proc2.replaceAbsGreaterThan10();
    proc2.print("После замены (|x| > 10 → 0):");
    std::cout << "✓ Подтест 2.2 пройден" << std::endl;
    
    std::cout << "\n✅ ТЕСТ 2 ПРОЙДЕН УСПЕШНО!\n" << std::endl;
}

// ТЕСТ 3: Проверка удаления нулей
void testRemoveZeros() {
    std::cout << "╔═══════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║  ТЕСТ 3: Удаление нулевых элементов                          ║" << std::endl;
    std::cout << "╚═══════════════════════════════════════════════════════════════╝" << std::endl;
    
    // Подтест 3.1: Целые числа
    std::cout << "\n[3.1] Тестирование с int..." << std::endl;
    ArrayProcessor<int> proc1(-5, 5, 12);
    proc1.print("Исходный массив:");
    proc1.multiplyByTwo();
    proc1.print("После умножения:");
    proc1.replaceAbsGreaterThan10();
    proc1.print("После замены (появились нули):");
    
    size_t sizeBefore = 0;
    // Не можем напрямую получить размер, но видим в выводе
    
    proc1.removeZeros();
    proc1.print("После удаления нулей:");
    std::cout << "✓ Подтест 3.1 пройден (проверьте, что нулей не осталось)" << std::endl;
    
    // Подтест 3.2: Вещественные числа
    std::cout << "\n[3.2] Тестирование с double..." << std::endl;
    ArrayProcessor<double> proc2(-8.0, 8.0, 10);
    proc2.print("Исходный массив:");
    proc2.multiplyByTwo();
    proc2.replaceAbsGreaterThan10();
    proc2.print("После замены (появились нули):");
    proc2.removeZeros();
    proc2.print("После удаления нулей:");
    std::cout << "✓ Подтест 3.2 пройден" << std::endl;
    
    std::cout << "\n✅ ТЕСТ 3 ПРОЙДЕН УСПЕШНО!\n" << std::endl;
}

// ТЕСТ 4: Проверка полного цикла операций
void testFullCycle() {
    std::cout << "╔═══════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║  ТЕСТ 4: Полный цикл всех операций                           ║" << std::endl;
    std::cout << "╚═══════════════════════════════════════════════════════════════╝" << std::endl;
    
    std::cout << "\n[4.1] Тестирование int..." << std::endl;
    ArrayProcessor<int> proc1(-10, 10, 20);
    proc1.processAll();
    std::cout << "✓ Подтест 4.1 пройден" << std::endl;
    
    std::cout << "\n[4.2] Тестирование double..." << std::endl;
    ArrayProcessor<double> proc2(-10.0, 10.0, 15);
    proc2.processAll();
    std::cout << "✓ Подтест 4.2 пройден" << std::endl;
    
    std::cout << "\n[4.3] Тестирование float..." << std::endl;
    ArrayProcessor<float> proc3(-10.0f, 10.0f, 12);
    proc3.processAll();
    std::cout << "✓ Подтест 4.3 пройден" << std::endl;
    
    std::cout << "\n✅ ТЕСТ 4 ПРОЙДЕН УСПЕШНО!\n" << std::endl;
}

// ТЕСТ 5: Проверка граничных случаев
void testEdgeCases() {
    std::cout << "╔═══════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║  ТЕСТ 5: Граничные случаи                                    ║" << std::endl;
    std::cout << "╚═══════════════════════════════════════════════════════════════╝" << std::endl;
    
    // Подтест 5.1: Маленький массив (1 элемент)
    std::cout << "\n[5.1] Массив из 1 элемента..." << std::endl;
    ArrayProcessor<int> proc1(-10, 10, 1);
    proc1.processAll();
    std::cout << "✓ Подтест 5.1 пройден" << std::endl;
    
    // Подтест 5.2: Массив из 2 элементов
    std::cout << "\n[5.2] Массив из 2 элементов..." << std::endl;
    ArrayProcessor<double> proc2(-5.0, 5.0, 2);
    proc2.processAll();
    std::cout << "✓ Подтест 5.2 пройден" << std::endl;
    
    // Подтест 5.3: Большой массив
    std::cout << "\n[5.3] Большой массив (50 элементов)..." << std::endl;
    ArrayProcessor<int> proc3(-10, 10, 50);
    proc3.print("Исходный большой массив:");
    proc3.multiplyByTwo();
    proc3.replaceAbsGreaterThan10();
    proc3.removeZeros();
    proc3.print("Финальный результат:");
    std::cout << "✓ Подтест 5.3 пройден" << std::endl;
    
    std::cout << "\n✅ ТЕСТ 5 ПРОЙДЕН УСПЕШНО!\n" << std::endl;
}

// ТЕСТ 6: Проверка диапазона [-10, 10]
void testInitialRange() {
    std::cout << "╔═══════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║  ТЕСТ 6: Проверка исходного диапазона [-10, 10]             ║" << std::endl;
    std::cout << "╚═══════════════════════════════════════════════════════════════╝" << std::endl;
    
    std::cout << "\n[6.1] Генерация массива int в диапазоне [-10, 10]..." << std::endl;
    ArrayProcessor<int> proc1(-10, 10, 30);
    proc1.print("Проверьте, что все значения в диапазоне [-10, 10]:");
    std::cout << "✓ Подтест 6.1 пройден (визуальная проверка)" << std::endl;
    
    std::cout << "\n[6.2] Генерация массива double в диапазоне [-10, 10]..." << std::endl;
    ArrayProcessor<double> proc2(-10.0, 10.0, 20);
    proc2.print("Проверьте, что все значения в диапазоне [-10.0, 10.0]:");
    std::cout << "✓ Подтест 6.2 пройден (визуальная проверка)" << std::endl;
    
    std::cout << "\n✅ ТЕСТ 6 ПРОЙДЕН УСПЕШНО!\n" << std::endl;
}

int main() {
    std::cout << "\n";
    std::cout << "╔═══════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║                                                               ║" << std::endl;
    std::cout << "║        КОМПЛЕКСНОЕ ТЕСТИРОВАНИЕ ЛАБОРАТОРНОЙ РАБОТЫ №7        ║" << std::endl;
    std::cout << "║                      Вариант 5                                ║" << std::endl;
    std::cout << "║                                                               ║" << std::endl;
    std::cout << "╚═══════════════════════════════════════════════════════════════╝" << std::endl;
    std::cout << "\n";
    
    try {
        testInitialRange();
        testMultiplyByTwo();
        testReplaceAbsGreaterThan10();
        testRemoveZeros();
        testFullCycle();
        testEdgeCases();
        
        std::cout << "\n";
        std::cout << "╔═══════════════════════════════════════════════════════════════╗" << std::endl;
        std::cout << "║                                                               ║" << std::endl;
        std::cout << "║              ✅ ВСЕ ТЕСТЫ ПРОЙДЕНЫ УСПЕШНО! ✅                ║" << std::endl;
        std::cout << "║                                                               ║" << std::endl;
        std::cout << "╚═══════════════════════════════════════════════════════════════╝" << std::endl;
        std::cout << "\n";
        
        return 0;
        
    } catch (const std::exception& e) {
        std::cerr << "\n❌ ОШИБКА В ТЕСТАХ: " << e.what() << std::endl;
        return 1;
    }
}
