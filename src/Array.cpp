#include "../include/Array.h"
#include <algorithm>
#include <iostream>

//Конструктор по умолчанию
Array::Array() : data(nullptr), size(0), capacity(0) {}

//Конструктор копирования (Глубокое копирование)
Array::Array(const Array& other) : size(other.size), capacity(other.capacity) {
    data = new Figure*[capacity];
    for (size_t i = 0; i < size; i++) {
        //Глубокое копирование - создаем копии фигур через clone()
        data[i] = other.data[i]->clone();
    }
}

//Конструктор перемещения
Array::Array(Array&& other) noexcept 
    : data(other.data), size(other.size), capacity(other.capacity) {
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

//Конструктор из initializer_list
Array::Array(const std::initializer_list<Figure*>& initList) 
    : size(initList.size()), capacity(initList.size()) {
    data = new Figure*[capacity];
    std::copy(initList.begin(), initList.end(), data);
}

//Деструктор
Array::~Array() {
    for (size_t i = 0; i < size; i++) {
        delete data[i]; //удаляем каждую фигуру
    }
    delete[] data; //удаляем массив указателей
}

//Копирующее присваивание (Глубокое копирование)
Array& Array::operator=(const Array& other) {
    if (this != &other) {
        // Освобождаем старые ресурсы
        for (size_t i = 0; i < size; i++) {
            delete data[i];
        }
        delete[] data;
        
        //Глубокое копирование - создаем копии фигур
        size = other.size;
        capacity = other.capacity;
        data = new Figure*[capacity];
        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i]->clone();
        }
    }
    return *this;
}

//Перемещающее присваивание
Array& Array::operator=(Array&& other) noexcept {
    if (this != &other) {
        //Освобождаем старые ресурсы
        for (size_t i = 0; i < size; i++) {
            delete data[i];
        }
        delete[] data;
        
        //Перемещаем ресурсы
        data = other.data;
        size = other.size;
        capacity = other.capacity;
        
        //Обнуляем other
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}

//Сравнение массивов (Глубокое сравнение)
bool Array::operator==(const Array& other) const {
    if (size != other.size) return false;
    for (size_t i = 0; i < size; i++) {
        //Глубокое сравнение - сравниваем фигуры через оператор ==
        if (*data[i] != *other.data[i]) return false;
    }
    return true;
}

bool Array::operator!=(const Array& other) const {
    return !(*this == other);
}

//Добавление фигуры
void Array::addFigure(Figure* figure) {
    if (size >= capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = figure;
}

//Удаление фигуры по индексу
void Array::deleteFigure(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    
    delete data[index]; //удаляем фигуру
    
    //Сдвигаем оставшиеся элементы
    for (size_t i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    size--;
}

//Получение фигуры по индексу
Figure* Array::getFigure(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

//Размер массива
size_t Array::getSize() const {
    return size;
}

// Вместимость массива
size_t Array::getCapacity() const {
    return capacity;
}

//Общая площадь всех фигур
double Array::totalArea() const {
    double total = 0;
    for (size_t i = 0; i < size; i++) {
        total += (double)(*data[i]); //использует operator double()
    }
    return total;
}

//Вывод всех фигур
void Array::printAll() const {
    for (size_t i = 0; i < size; i++) {
        std::cout <<"\n" << *data[i] << std::endl;
    }
}

//Увеличение вместимости массива
void Array::resize(size_t new_capacity) {
    Figure** new_data = new Figure*[new_capacity];
    
    // Копируем старые указатели
    for (size_t i = 0; i < size; i++) {
        new_data[i] = data[i];
    }
    
    delete[] data;     //удаляем старый массив
    data = new_data;   //обновляем указатель
    capacity = new_capacity;
}