#include "../include/Triangle.h"
#include "../include/Point.h"

//Конструктор квадрата без аргументов
Triangle::Triangle() : Figure("Triangle"){}

//Конструктор с именем фигуры
Triangle::Triangle(std::string name) : Figure(name){}

// Конструктор с initializer_list
Triangle::Triangle(std::initializer_list<Point> pointList) : Figure("Triangle"){
        if (pointList.size() != 3) {
            throw std::invalid_argument("Triangle requires exactly 3 points");
        }
        // Копируем точки из initializer_list в массив points
        std::copy(pointList.begin(), pointList.end(), points);
    }

Point Triangle:: center_figure() const{
    double x_center {0}, y_center {0};
    for (int i = 0; i < 3; i++){
        x_center += points[i].x;
        y_center += points[i].y;
    }
    x_center /= 3;
    y_center /= 3;
    Point center = Point(x_center, y_center);
    return center;
}


void Triangle:: write_figure(std::ostream& os) const{
    for (int i = 'A'; i < 'D'; i++){
        os << "Точки "<< name_fig <<": " << (char)i << points[i-'A'] << "\n";
    }
    os << "Точка центра: O" << center_figure() << "\n";
    os << "Площадь Треугольника: " << area_figure();
}


void Triangle:: read_figure(std::istream& is){
    std::cout << "Введите 3 точки треугольника в формате (x, y) через пробел: ";
    
    for (int i = 0; i < 3; i++) {
        Point p;
        is >> p;  // используем перегруженный operator>> для Point
        points[i] = p;
    }

    // Проверяем, что ввод прошел успешно
    if (!is) {
        std::cout << "Ошибка ввода!" << std::endl;
    }
}


double Triangle:: area_figure() const{
    Point center = center_figure();
    double dx = points[0].x - center.x;
    double dy = points[0].y - center.y;
    return 1.2990381056*(dx*dx + dy*dy);
}


bool Triangle::operator==(const Triangle& other) const {
    //Сравниваем имя фигуры
    if (name_fig != other.name_fig) return false;
    //Сравниваем все 3 точки
    for (int i = 0; i < 3; i++) {
        if (points[i].x != other.points[i].x || 
            points[i].y != other.points[i].y) {
            return false;
        }
    }
    return true;
}

//Деструктор(удаляем массив точек)
Triangle::~Triangle(){
    delete[] points;
}