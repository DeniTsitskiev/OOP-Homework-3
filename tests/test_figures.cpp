#include <gtest/gtest.h>
#include "../include/Figure.h"
#include "../include/Square.h"
#include "../include/Triangle.h"
#include "../include/Octagon.h"
#include "../include/Point.h"

// Тесты для Point
TEST(PointTest, DefaultConstructor) {
    Point p;
    EXPECT_DOUBLE_EQ(p.x, 0);
    EXPECT_DOUBLE_EQ(p.y, 0);
}

TEST(PointTest, ParameterizedConstructor) {
    Point p(3.5, 2.8);
    EXPECT_DOUBLE_EQ(p.x, 3.5);
    EXPECT_DOUBLE_EQ(p.y, 2.8);
}

TEST(PointTest, InputOutputOperator) {
    Point p1(1.5, 2.5);
    std::stringstream ss;
    ss << p1;
    EXPECT_EQ(ss.str(), "(1.5, 2.5)");
    
    Point p2;
    ss >> p2;
    EXPECT_DOUBLE_EQ(p2.x, 1.5);
    EXPECT_DOUBLE_EQ(p2.y, 2.5);
}

// Тесты для Square
TEST(SquareTest, DefaultConstructor) {
    Square square;
    EXPECT_NO_THROW(square.area_figure());
}

TEST(SquareTest, InitializerListConstructor) {
    Square square({Point(0,0), Point(1,0), Point(1,1), Point(0,1)});
    EXPECT_DOUBLE_EQ(square.area_figure(), 1.0);
}

TEST(SquareTest, CopyConstructor) {
    Square square1({Point(0,0), Point(2,0), Point(2,2), Point(0,2)});
    Square square2 = square1;
    EXPECT_TRUE(square1 == square2);
}

TEST(SquareTest, MoveConstructor) {
    Square square1({Point(0,0), Point(1,0), Point(1,1), Point(0,1)});
    Square square2 = std::move(square1);
    EXPECT_DOUBLE_EQ(square2.area_figure(), 1.0);
}

TEST(SquareTest, AreaCalculation) {
    Square square({Point(0,0), Point(3,0), Point(3,3), Point(0,3)});
    EXPECT_DOUBLE_EQ(square.area_figure(), 9.0);
}

TEST(SquareTest, CenterCalculation) {
    Square square({Point(1,1), Point(3,1), Point(3,3), Point(1,3)});
    Point center = square.center_figure();
    EXPECT_DOUBLE_EQ(center.x, 2.0);
    EXPECT_DOUBLE_EQ(center.y, 2.0);
}

// Тесты для Triangle
TEST(TriangleTest, DefaultConstructor) {
    Triangle triangle;
    EXPECT_NO_THROW(triangle.area_figure());
}

TEST(TriangleTest, EquilateralTriangleArea) {
    Triangle triangle({Point(0,0), Point(2,0), Point(1,1.732)});
    EXPECT_NEAR(triangle.area_figure(), 1.732, 0.01);
}

TEST(TriangleTest, CopyAssignment) {
    Triangle triangle1({Point(0,0), Point(3,0), Point(1.5,2.598)});
    Triangle triangle2;
    triangle2 = triangle1;
    EXPECT_TRUE(triangle1 == triangle2);
}

// Тесты для Octagon
TEST(OctagonTest, DefaultConstructor) {
    Octagon octagon;
    EXPECT_NO_THROW(octagon.area_figure());
}

TEST(OctagonTest, RegularOctagonArea) {
    Octagon octagon({
        Point(1,0), Point(0.707,0.707), Point(0,1), Point(-0.707,0.707),
        Point(-1,0), Point(-0.707,-0.707), Point(0,-1), Point(0.707,-0.707)
    });
    EXPECT_NEAR(octagon.area_figure(), 2.828, 0.01);
}

TEST(OctagonTest, CloneMethod) {
    Octagon octagon1({
        Point(1,0), Point(0.707,0.707), Point(0,1), Point(-0.707,0.707),
        Point(-1,0), Point(-0.707,-0.707), Point(0,-1), Point(0.707,-0.707)
    });
    Figure* cloned = octagon1.clone();
    EXPECT_NEAR(cloned->area_figure(), 2.828, 0.01);
    delete cloned;
}