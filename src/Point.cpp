#include "../include/Point.h"

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& p) {
    char ch;
    
    // Пропускаем пробелы и читаем '('
    is >> std::ws >> ch;
    if (ch != '(') {
        is.setstate(std::ios::failbit);
        return is;
    }
    
    // Читаем x
    is >> p.x;
    
    // Пропускаем пробелы и читаем ','
    is >> std::ws >> ch;
    if (ch != ',') {
        is.setstate(std::ios::failbit);
        return is;
    }
    
    // Читаем y
    is >> p.y;
    
    // Пропускаем пробелы и читаем ')'
    is >> std::ws >> ch;
    if (ch != ')') {
        is.setstate(std::ios::failbit);
        return is;
    }
    
    return is;
}