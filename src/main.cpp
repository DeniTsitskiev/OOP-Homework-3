/*
Работу выполнил: Студент группы М8О-203БВ-24 Цицкиев Д.Р.
Вариант: 32
Необходимо реализовать: Восьмиугольник, Треугольник, Квадрат
*/

#include "./Figure.cpp"
#include "./Square.cpp"
#include "./Triangle.cpp"
#include "./Octagon.cpp"
#include "./Point.cpp"

#include <Windows.h>


int main(){
    SetConsoleOutputCP(65001); // UTF-8
    Square square1 = Square(); //Инициализация без аргументов
    //Инициализация по имени фигуры, потом используем для демонстрации перегрузки ==
    Square square2 = Square("Квадрат 2");
    Square square3 = Square("Квадрат 2");
    Square square4 = Square("Квадрат 4");

    Triangle triangle1 = {Point(0, 0), Point(3, 0), Point(1.5, 2.598)}; //Инициализация через initializer_list
    Octagon octagon1 =  {   Point(1, 0),  Point(0.707, 0.707), 
                            Point(0, 1),  Point(-0.707, 0.707), 
                            Point(-1, 0), Point(-0.707, -0.707), 
                            Point(0, -1), Point(0.707, -0.707)};
    //Ввод точек осуществляется через перегруженный оператор >> (Можно взять (1, 2) (2, 4) (3, 1) (4, 3) для теста. Площадь 5, Центр (2.5, 2.5))
    std::cin >> square1;
    //Вывод всей информации о фигуре осуществляется через перегруженный оператор <<
    std::cout << square1 << "\n" << std::endl;
    std::cout << triangle1 << "\n" << std::endl;
    std::cout << octagon1 << "\n" << std::endl;


    //Демонстрация работы методов и других перегрузок:


    //2 способа вывода площади:
    //Прямой вызов метода area_figure
    std::cout << "Площадь квадрата 1 способом:" << std::endl;
    std::cout << square1.area_figure() << std::endl;
    //Перегрузка (double) для вывода площади
    std::cout << "Площадь квадрата 2 способом:" << std::endl;
    std::cout << (double)square1 << std::endl;
    return 0;
}
