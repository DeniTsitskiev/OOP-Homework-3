#ifndef ARRAY_H
#define ARRAY_H

#include "Figure.h"
#include <stdexcept>

class Array {
private:
    Figure** data;        // массив указателей на Figure
    size_t size;          // текущее количество элементов
    size_t capacity;      // вместимость массива
    
    void resize(size_t new_capacity); // увеличение capacity

public:
    // Конструкторы
    Array();
    Array(const Array& other);          //копирование
    Array(Array&& other) noexcept;      //перемещение
    Array(const std::initializer_list<Figure*>& initList);
    
    // Деструктор
    ~Array();
    
    // Операторы присваивания
    Array& operator=(const Array& other); //копирующее присваивание
    Array& operator=(Array&& other) noexcept; //перемещающее присваивание
    
    // Операторы сравнения
    bool operator==(const Array& other) const;
    bool operator!=(const Array& other) const;
    
    // Методы для работы с фигурами
    void addFigure(Figure* figure);
    void deleteFigure(size_t index);
    Figure* getFigure(size_t index) const;
    size_t getSize() const;
    size_t getCapacity() const;
    
    // Общие функции из задания
    double totalArea() const;
    void printAll() const;
};

#endif