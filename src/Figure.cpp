#include <string>
#include "../include/Figure.h"
//Конструктор без аргументов
Figure::Figure(): name_fig("Figure"){}

//Конструктор с именем фигуры
Figure::Figure(std::string name): name_fig(name){}

//Перегрузка <<
std::ostream& operator<<(std::ostream& os, const Figure& figure){
    figure.write_figure(os);
    return os;
}
//Перегрузка >>
std::istream& operator>>(std::istream& is, Figure& figure){
    figure.read_figure(is);
    return is;
}

//Оператор double для вывода площади
Figure::operator double() const{
    return area_figure();
}