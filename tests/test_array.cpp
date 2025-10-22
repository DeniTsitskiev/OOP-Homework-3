#include <gtest/gtest.h>
#include "../include/Array.h"
#include "../include/Square.h"
#include "../include/Triangle.h"
#include "../include/Octagon.h"

TEST(ArrayTest, DefaultConstructor) {
    Array array;
    EXPECT_EQ(array.getSize(), 0);
    EXPECT_EQ(array.getCapacity(), 0);
}

TEST(ArrayTest, AddFigures) {
    Array array;
    array.addFigure(new Square({Point(0,0), Point(1,0), Point(1,1), Point(0,1)}));
    array.addFigure(new Triangle({Point(0,0), Point(2,0), Point(1,1.732)}));
    
    EXPECT_EQ(array.getSize(), 2);
}

TEST(ArrayTest, TotalAreaCalculation) {
    Array array;
    array.addFigure(new Square({Point(0,0), Point(2,0), Point(2,2), Point(0,2)})); // площадь = 4
    array.addFigure(new Triangle({Point(0,0), Point(3,0), Point(1.5,2.598)})); // площадь ≈ 3.897
    
    EXPECT_NEAR(array.totalArea(), 7.897, 0.01);
}

TEST(ArrayTest, DeleteFigure) {
    Array array;
    array.addFigure(new Square());
    array.addFigure(new Triangle());
    array.addFigure(new Octagon());
    
    EXPECT_EQ(array.getSize(), 3);
    array.deleteFigure(1);
    EXPECT_EQ(array.getSize(), 2);
}

TEST(ArrayTest, CopyConstructor) {
    Array array1;
    array1.addFigure(new Square({Point(0,0), Point(1,0), Point(1,1), Point(0,1)}));
    
    Array array2 = array1;
    EXPECT_EQ(array1.getSize(), array2.getSize());
    EXPECT_NEAR(array1.totalArea(), array2.totalArea(), 0.001);
}

TEST(ArrayTest, AssignmentOperator) {
    Array array1;
    array1.addFigure(new Square({Point(0,0), Point(2,0), Point(2,2), Point(0,2)}));
    
    Array array2;
    array2 = array1;
    EXPECT_EQ(array1.getSize(), array2.getSize());
    EXPECT_NEAR(array1.totalArea(), array2.totalArea(), 0.001);
}

TEST(ArrayTest, OutOfRangeAccess) {
    Array array;
    EXPECT_THROW(array.getFigure(0), std::out_of_range);
    EXPECT_THROW(array.deleteFigure(0), std::out_of_range);
}