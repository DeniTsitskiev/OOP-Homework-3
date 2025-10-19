#ifndef POINT_H
#define POINT_H

#include <iostream>

struct Point {
    double x, y;
    
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    
    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    
    // Оператор ввода для формата (x, y)
    friend std::istream& operator>>(std::istream& is, Point& p);
};


#endif