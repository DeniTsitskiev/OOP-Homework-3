#ifndef OCTAGON_H
#define OCTAGON_H


#include <ostream>
#include <string>
#include "./Figure.h"

class Octagon: public Figure{
    private:
        //Массив на куче. Элементы - структуры Point
        Point* points = new Point[8];
    public:
        //Конструкторы
        Octagon();
        Octagon(std::string name);
        Octagon(std::initializer_list<Point> pointList);     // Конструктор с initializer_list
        //Функции из задания
        Point center_figure() const override;               //Поиск центра
        void write_figure(std::ostream& os) const override; //Меняет поток os, чтобы << выводил информацию о фигуре на экран
        void read_figure(std::istream& is) override;        //Меняет поток is, чтобы >> заполнил массив точек
        double area_figure() const override;                //Поиск площади
        // Оператор сравнения
        bool operator==(const Octagon& other) const;
        //Деструктор
        ~Octagon();
};

#endif