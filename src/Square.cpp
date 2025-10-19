#include "../include/Square.h"
#include "../include/Point.h"

//Конструктор квадрата без аргументов
Square::Square() : Figure("Square"){}

//Конструктор с именем фигуры
Square::Square(std::string name) : Figure(name){}

// Конструктор с initializer_list
Square::Square(std::initializer_list<Point> pointList) : Figure("Square"){
        if (pointList.size() != 4) {
            throw std::invalid_argument("Square requires exactly 4 points");
        }
        // Копируем точки из initializer_list в массив points
        std::copy(pointList.begin(), pointList.end(), points);
    }

Point Square:: center_figure() const{
    double x_center {0}, y_center {0};
    for (int i = 0; i < 4; i++){
        x_center += points[i].x;
        y_center += points[i].y;
    }
    x_center /= 4;
    y_center /= 4;
    Point center = Point(x_center, y_center);
    return center;
}


void Square:: write_figure(std::ostream& os) const{
    for (int i = 'A'; i < 'E'; i++){
        os << "Точки "<< name_fig <<": " << (char)i << points[i-'A'] << "\n";
    }
    os << "Точка центра: O" << center_figure() << "\n";
    os << "Площадь Квадрата: " << area_figure();
}


void Square:: read_figure(std::istream& is){
    std::cout << "Введите 4 точки квадрата в формате (x, y) через пробел: ";
    
    for (int i = 0; i < 4; i++) {
        Point p;
        is >> p;  // используем перегруженный operator>> для Point
        points[i] = p;
    }

    // Проверяем, что ввод прошел успешно
    if (!is) {
        std::cout << "Ошибка ввода!" << std::endl;
    }
}


double Square:: area_figure() const{
    Point center = center_figure();
    double dx = points[0].x - center.x;
    double dy = points[0].y - center.y;
    return 2.0*(dx*dx + dy*dy);
}


bool Square::operator==(const Square& other) const {
    //Сравниваем имя фигуры
    if (name_fig != other.name_fig) return false;
    //Сравниваем все 4 точки
    for (int i = 0; i < 4; i++) {
        if (points[i].x != other.points[i].x || 
            points[i].y != other.points[i].y) {
            return false;
        }
    }
    return true;
}

//Деструктор(удаляем массив точек)
Square::~Square(){
    delete[] points;
}