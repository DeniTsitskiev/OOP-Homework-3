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
#include "./Array.cpp"

// #include <Windows.h>


int main(){
    // SetConsoleOutputCP(65001); // UTF-8 - Для запуска на винде
    
    std::cout << "ДЕМОНСТРАЦИЯ РАБОТЫ ПРОГРАММЫ\n" << std::endl;

    // Создание фигур разными способами
    std::cout << "СОЗДАНИЕ ФИГУР:" << std::endl;
    Square square1 = Square(); //Инициализация без аргументов
    Triangle triangle1 = {Point(0, 0), Point(3, 0), Point(1.5, 2.598)}; //Инициализация через initializer_list
    Octagon octagon1 =  {   Point(1, 0),  Point(0.707, 0.707), 
                            Point(0, 1),  Point(-0.707, 0.707), 
                            Point(-1, 0), Point(-0.707, -0.707), 
                            Point(0, -1), Point(0.707, -0.707)};

    std::cout << "Фигуры созданы успешно!\n" << std::endl;

    // Демонстрация ввода для квадрата
    std::cout << "ВВОД ДАННЫХ ДЛЯ ФИГУР (например, (1, 2) (2, 4) (3, 1) (4, 3)):" << std::endl;

    //Ввод точек осуществляется через перегруженный оператор >> 
    // (Можно взять (1, 2) (2, 4) (3, 1) (4, 3) для теста. Площадь должна быть 5, Центр (2.5, 2.5))
    std::cin >> square1;

    // Вывод информации о фигурах
    std::cout << "ВЫВОД ИНФОРМАЦИИ О ФИГУРАХ:" << std::endl;
    //Вывод всей информации о фигуре осуществляется через перегруженный оператор <<
    std::cout << square1 << "\n" << std::endl;
    
    std::cout << triangle1 << "\n" << std::endl;
    
    std::cout << octagon1 << "\n" << std::endl;

    // Демонстрация методов
    std::cout << "ДЕМОНСТРАЦИЯ МЕТОДОВ:" << std::endl;
    
    //2 способа вывода площади:
    std::cout << "Площадь квадрата:" << std::endl;
    //Прямой вызов метода area_figure
    std::cout << "  1 способ (area_figure()): " << square1.area_figure() << std::endl;
    //Перегрузка (double) для вывода площади
    std::cout << "  2 способ (operator double()): " << (double)square1 << std::endl;

    std::cout << "\nГеометрический центр треугольника: " << triangle1.center_figure() << std::endl;
    std::cout << "Геометрический центр восьмиугольника: " << octagon1.center_figure() << std::endl;

    // Демонстрация копирования и перемещения
    std::cout << "\nДЕМОНСТРАЦИЯ КОПИРОВАНИЯ И ПЕРЕМЕЩЕНИЯ:" << std::endl;
    
    // Копирование
    Square square2 = square1; // конструктор копирования
    Triangle triangle2(triangle1); // тоже конструктор копирования
    std::cout << "Созданы копии фигур через конструктор копирования" << std::endl;
    
    // Присваивание
    Square square3;
    square3 = square1; // оператор присваивания
    std::cout << "Создана копия через оператор присваивания" << std::endl;

    // Сравнение
    std::cout << "square1 == square2: " << (square1 == square2 ? "true" : "false") << std::endl;
    std::cout << "square1 != square3: " << (square1 != square3 ? "true" : "false") << std::endl;

    // Демонстрация работы с массивом Array
    std::cout << "РАБОТА С МАССИВОМ ARRAY:" << std::endl;
    
    Array figures;
    figures.addFigure(new Square(square1));
    figures.addFigure(new Triangle(triangle1));
    figures.addFigure(new Octagon(octagon1));
    
    std::cout << "Добавлено фигур в массив: " << figures.getSize() << std::endl;
    std::cout << "Общая площадь всех фигур в массиве: " << figures.totalArea() << std::endl;
    
    std::cout << "\nВсе фигуры в массиве:" << std::endl;
    figures.printAll();

    // Демонстрация удаления из массива
    std::cout << "\nУдаляем первую фигуру из массива..." << std::endl;
    figures.deleteFigure(0);
    std::cout << "Осталось фигур: " << figures.getSize() << std::endl;
    std::cout << "Новая общая площадь: " << figures.totalArea() << std::endl;

    // Демонстрация копирования массива
    std::cout << "\nКОПИРОВАНИЕ МАССИВА:" << std::endl;
    Array figuresCopy = figures; // конструктор копирования массива
    std::cout << "Создана копия массива, размер: " << figuresCopy.getSize() << std::endl;
    std::cout << "Массивы равны: " << (figures == figuresCopy ? "true" : "false") << std::endl;

    return 0;
}