#include <iostream>

// Класс FractionNumber
class FractionNumber {
private:
    int* numerator;
    int* denominator;
    static int operationsCount;

public:
    // Конструктор с параметрами
    FractionNumber(int num, int denom) : numerator(new int(num)), denominator(new int(denom)) {}

    // Конструктор копирования
    FractionNumber(const FractionNumber& otherFraction)
        : numerator(new int(*otherFraction.numerator)), denominator(new int(*otherFraction.denominator)) {}

    // Конструктор по умолчанию
    FractionNumber() : FractionNumber(5, 9) {}

    // Деструктор
    ~FractionNumber() {
        delete numerator;
        delete denominator;
        std::cout << "Fraction object is being destroyed." << std::endl;
    }

    FractionNumber add(const FractionNumber& otherFraction) {
        int resultNum = *numerator * (*otherFraction.denominator) + (*otherFraction.numerator) * *denominator;
        int resultDenom = *denominator * (*otherFraction.denominator);
        FractionNumber::operationsCount++;
        return FractionNumber(resultNum, resultDenom);
    }

    FractionNumber subtract(const FractionNumber& otherFraction) {
        int resultNum = *numerator * (*otherFraction.denominator) - (*otherFraction.numerator) * *denominator;
        int resultDenom = *denominator * (*otherFraction.denominator);
        FractionNumber::operationsCount++;
        return FractionNumber(resultNum, resultDenom);
    }

    FractionNumber multiply(const FractionNumber& otherFraction) {
        int resultNum = *numerator * (*otherFraction.numerator);
        int resultDenom = *denominator * (*otherFraction.denominator);
        FractionNumber::operationsCount++;
        return FractionNumber(resultNum, resultDenom);
    }

    FractionNumber divide(const FractionNumber& otherFraction) {
        int resultNum = *numerator * (*otherFraction.denominator);
        int resultDenom = *denominator * (*otherFraction.numerator);
        FractionNumber::operationsCount++;
        return FractionNumber(resultNum, resultDenom);
    }

    void display() const {
        std::cout << *numerator << "/" << *denominator << std::endl;
    }

    static void displayCount() {
        std::cout << "Number of Fraction objects created: " << operationsCount << std::endl;
    }
};

int FractionNumber::operationsCount = 0;

// Шаблонный класс Node
template <typename T>
struct Node {
    T* data; // Данные узла
    Node* next; // Указатель на следующий узел

    // Конструктор узла
    Node(T* frac) : data(frac), next(nullptr) {}

    // Деструктор узла
    ~Node() {
        delete data;
    }
};

// Шаблонный класс Deque
template <typename T>
class Deque {
private:
    Node<T>* head; // Указатель на голову списка
    Node<T>* tail; // Указатель на хвост списка

public:
    // Конструктор по умолчанию
    Deque() : head(nullptr), tail(nullptr) {}

    // Деструктор
    ~Deque() {
        while (head) { // Удаление всех узлов списка
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Метод добавления элемента в начало
    void addFront(T* frac) {
        Node<T>* newNode = new Node<T>(frac);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Метод добавления элемента в конец
    void addRear(T* frac) {
        Node<T>* newNode = new Node<T>(frac);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Метод удаления элемента из начала
    void removeFront() {
        if (!head) {
            std::cerr << "Deque is empty." << std::endl;
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        if (!head) {
            tail = nullptr;
        }
        delete temp;
    }

    // Метод вставки элемента по индексу
    void insertAt(int index, T* frac) {
        if (index == 0) {
            addFront(frac);
            return;
        }
        Node<T>* current = head;
        for (int i = 0; i < index - 1 && current; ++i) {
            current = current->next;
        }
        if (!current) {
            std::cerr << "Index out of bounds." << std::endl;
            return;
        }
        Node<T>* newNode = new Node<T>(frac);
        newNode->next = current->next;
        current->next = newNode;
        if (!newNode->next) {
            tail = newNode;
        }
    }

    // Метод удаления элемента по индексу
    void removeAt(int index) {
        if (index == 0 && head) {
            removeFront();
            return;
        }
        Node<T>* current = head;
        for (int i = 0; i < index - 1 && current; ++i) {
            current = current->next;
        }
        if (!current || !current->next) {
            std::cerr << "Index out of bounds." << std::endl;
            return;
        }
        Node<T>* temp = current->next;
        current->next = temp->next;
        if (!current->next) {
            tail = current;
        }
        delete temp;
    }

    // Метод поиска элемента по индексу
    T* find(int index) {
        Node<T>* current = head;
        for (int i = 0; i < index && current; ++i) {
            current = current->next;
        }
        if (!current) {
            std::cerr << "Index out of bounds." << std::endl;
            return nullptr;
        }
        return current->data;
    }

    // Метод отображения всех элементов списка
    void displayAll() const {
        Node<T>* current = head;
        while (current) {
            current->data->display();
            current = current->next;
        }
    }

    // Метод отображения всех элементов списка для встроенных типов
    void displayAllBasic() const {
        Node<T>* current = head;
        while (current) {
            std::cout << *(current->data) << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

