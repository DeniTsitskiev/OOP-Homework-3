#ifndef FIGURE_H
#define FIGURE_H


#include <string>
#include "./Point.h"

//Абстрактный класс фигуры
class Figure{
    protected:
        std::string name_fig;
    public:
        //Конструкторы
        Figure();
        Figure(std::string);
        //Виртуальные функции из задания
        virtual Point center_figure() const = 0;
        virtual void write_figure(std::ostream& os) const = 0;
        virtual void read_figure(std::istream& is) = 0;
        virtual double area_figure() const = 0;
        //Виртуальный деструктор
        virtual ~Figure() = default;
        // Виртуальный метод для клонирования
        virtual Figure* clone() const = 0;
        //Перегрузка операторов
        friend std::ostream& operator<<(std::ostream& os, const Figure& figure);
        friend std::istream& operator<<(std::istream& is, Figure& figure);
        virtual operator double() const;
};
#endif