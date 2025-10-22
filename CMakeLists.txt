cmake_minimum_required(VERSION 3.16)
project(OOP_Lab3)

# Настройка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включение необходимых модулей
include(CTest)
include(FetchContent)

# Установка Google Test
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.0
    TLS_VERIFY false
)

# Отключаем использование статической библиотеки и переключаем на динамическую
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Создаем библиотеку из общих исходных файлов
add_library(common_lib STATIC
    src/Figure.cpp
    src/Square.cpp  
    src/Triangle.cpp
    src/Octagon.cpp
    src/Point.cpp
    src/Array.cpp
)

# Указываем пути к заголовочным файлам для библиотеки
target_include_directories(common_lib PUBLIC include)

# Основная программа
add_executable(main src/main.cpp)

# Связываем основную программу с библиотекой
target_link_libraries(main PRIVATE common_lib ${CMAKE_THREAD_LIBS_INIT})

# Тесты
add_executable(tests
    tests/test_main.cpp
    tests/test_figures.cpp
    tests/test_array.cpp
)

# Подключаем библиотеку и GoogleTest к тестам
target_include_directories(tests PRIVATE include)
target_link_libraries(tests PRIVATE common_lib gtest_main gmock_main)

# Включение компилятора для GoogleTest
target_compile_definitions(tests PRIVATE GTEST_HAS_TR1_TUPLE=0)

# Добавляем тесты в CTest
enable_testing()
add_test(NAME AllTests COMMAND tests)