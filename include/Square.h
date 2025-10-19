#ifndef SQUARE_H
#define SQUARE_H


#include <ostream>
#include <string>
#include "./Figure.h"

class Square: public Figure{
    private:
        //Массив на куче. Элементы - структуры Point
        Point* points = new Point[4];
        //{Point(1, 2), Point(2, 4), Point(3, 1), Point(4,3)};
    public:
        //Конструкторы
        Square();
        Square(std::string name);
        Square(std::initializer_list<Point> pointList);     // Конструктор с initializer_list
        //Функции из задания
        Point center_figure() const override;               //Поиск центра
        void write_figure(std::ostream& os) const override; //Меняет поток os, чтобы << выводил информацию о фигуре на экран
        void read_figure(std::istream& is) override;        //Меняет поток is, чтобы >> заполнил массив точек
        double area_figure() const override;                //Поиск площади
        // Оператор сравнения
        bool operator==(const Square& other) const;
        //Деструктор
        ~Square();
};

#endif