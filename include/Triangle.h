#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <ostream>
#include <string>
#include "./Figure.h"

class Triangle: public Figure{
    private:
        //Массив на куче. Элементы - структуры Point
        Point* points = new Point[3];
    public:
        //Конструкторы
        Triangle();

        //Конструкторы копирования и перемещения
        Triangle(const Triangle& other);                    //Конструктор копирования
        Triangle(Triangle&& other) noexcept;                //Конструктор перемещения
        
        //Операторы присваивания
        Triangle& operator=(const Triangle& other);         //Копирующее присваивание
        Triangle& operator=(Triangle&& other) noexcept;     //Перемещающее присваивание

        Triangle(std::string);
        Triangle(std::initializer_list<Point> pointList);     //Конструктор с initializer_list
        
        //Функции из задания
        Point center_figure() const override;               //Поиск центра
        void write_figure(std::ostream& os) const override; //Меняет поток os, чтобы << выводил информацию о фигуре на экран
        void read_figure(std::istream& is) override;        //Меняет поток is, чтобы >> заполнил массив точек
        double area_figure() const override;                //Поиск площади

        Figure* clone() const override;
        
        // ОПЕРАТОРЫ СРАВНЕНИЯ
        bool operator==(const Triangle& other) const;
        bool operator!=(const Triangle& other) const;
        
        //Деструктор
        ~Triangle();
};

#endif