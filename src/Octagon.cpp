#include "../include/Octagon.h"
#include "../include/Point.h"
#include <algorithm> // для std::copy

//Конструктор восьмиугольника без аргументов
Octagon::Octagon() : Figure("Octagon"){}

//Конструктор копирования
Octagon::Octagon(const Octagon& other) 
    : Figure(other), //копируем базовый класс (name_fig)
      points(new Point[8]) //выделяем новую память
{
    std::copy(other.points, other.points + 8, points);
}

//Конструктор перемещения
Octagon::Octagon(Octagon&& other) noexcept 
    : Figure(std::move(other)), //перемещаем базовый класс
      points(other.points)      //забираем массив точек
{
    other.points = nullptr; //обнуляем у исходного объекта
}

// ОПЕРАТОР КОПИРУЮЩЕГО ПРИСВАИВАНИЯ
Octagon& Octagon::operator=(const Octagon& other) {
    if (this != &other) {       //защита от самоприсваивания
        //Копируем базовый класс
        Figure::operator=(other);
        
        //Копируем точки
        std::copy(other.points, other.points + 8, points);
    }
    return *this;
}

//Оператор перемещающего присваивания
Octagon& Octagon::operator=(Octagon&& other) noexcept {
    if (this != &other) { // защита от самоприсваивания
        //Освобождаем свои ресурсы
        delete[] points;
        //Перемещаем базовый класс
        Figure::operator=(std::move(other));
        //Забираем ресурсы у other
        points = other.points;
        other.points = nullptr; //обнуляем у исходного объекта
    }
    return *this;
}



//Конструктор с именем фигуры
Octagon::Octagon(std::string name) : Figure(name){}

// Конструктор с initializer_list
Octagon::Octagon(std::initializer_list<Point> pointList) : Figure("Octagon") {
        if (pointList.size() != 8) {
            throw std::invalid_argument("Octagon requires exactly 8 points");
        }
        // Копируем точки из initializer_list в массив points
        std::copy(pointList.begin(), pointList.end(), points);
    }

Figure* Octagon::clone() const {
    return new Octagon(*this); // использует конструктор копирования
}

Point Octagon:: center_figure() const{
    double x_center {0}, y_center {0};
    for (int i = 0; i < 8; i++){
        x_center += points[i].x;
        y_center += points[i].y;
    }
    x_center /= 8;
    y_center /= 8;
    Point center = Point(x_center, y_center);
    return center;
}


void Octagon:: write_figure(std::ostream& os) const{
    for (int i = 'A'; i < 'I'; i++){
        os << "Точки "<< name_fig <<": " << (char)i << points[i-'A'] << "\n";
    }
    os << "Точка центра: O" << center_figure() << "\n";
    os << "Площадь Восьмиугольника: " << area_figure();
}


void Octagon:: read_figure(std::istream& is){
    std::cout << "Введите 8 точек восьмиугольника в формате (x, y) через пробел: ";
    
    for (int i = 0; i < 8; i++) {
        Point p;
        is >> p;  // используем перегруженный operator>> для Point
        points[i] = p;
    }

    // Проверяем, что ввод прошел успешно
    if (!is) {
        std::cout << "Ошибка ввода!" << std::endl;
    }
}


double Octagon:: area_figure() const{
    Point center = center_figure();
    double dx = points[0].x - center.x;
    double dy = points[0].y - center.y;
    return 2.8284271247*(dx*dx + dy*dy);
}

//Оператор неравенства
bool Octagon::operator!=(const Octagon& other) const {
    return !(*this == other);
}

bool Octagon::operator==(const Octagon& other) const {
    //Сравниваем имя фигуры
    if (name_fig != other.name_fig) return false;
    //Сравниваем все 8 точек
    for (int i = 0; i < 8; i++) {
        if (points[i].x != other.points[i].x || 
            points[i].y != other.points[i].y) {
            return false;
        }
    }
    return true;
}

//Деструктор(удаляем массив точек)
Octagon::~Octagon(){
    delete[] points;
}