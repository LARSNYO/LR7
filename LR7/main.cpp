#include "include.h"

// Тестирование шаблонного класса Deque
int main() {
    // Тестирование с int
    Deque<int> intDeque;
    intDeque.addRear(new int(10));
    intDeque.addFront(new int(20));
    intDeque.insertAt(1, new int(15));
    intDeque.displayAllBasic(); // Ожидаемый вывод: 20 15 10

    // Тестирование с float
    Deque<float> floatDeque;
    floatDeque.addRear(new float(10.5f));
    floatDeque.addFront(new float(20.5f));
    floatDeque.insertAt(1, new float(15.5f));
    floatDeque.displayAllBasic(); // Ожидаемый вывод: 20.5 15.5 10.5

    // Тестирование с FractionNumber
    Deque<FractionNumber> fracDeque;
    fracDeque.addRear(new FractionNumber(1, 2));
    fracDeque.addFront(new FractionNumber(3, 4));
    fracDeque.insertAt(1, new FractionNumber(5, 6));
    fracDeque.displayAll(); // Ожидаемый вывод: 3/4, 5/6, 1/2

    return 0;
}
