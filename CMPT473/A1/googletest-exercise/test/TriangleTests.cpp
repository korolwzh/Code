#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Triangle.h"

using namespace testing;
using namespace shapes;


//fail by the wrong algo of getperimeter() function
//which should be side1 + side2 + side3;
TEST(TriangleTests, testgetPerimeter)
{
    Triangle triangle(5,4,3);
    ASSERT_EQ(12, triangle.getPerimeter());
}

//fail by the wrong getperimeter() function
TEST(TriangleTests, testgetArea)
{
    Triangle triangle(5,4,3);
    ASSERT_EQ(6, triangle.getArea());
}

//fail by wrong logic of bool getkind() function
//which should test isEquilateral() before isIsosceles()
TEST(TriangleTests, testgetKind)
{
    Triangle triangle(3,3,3);
    ASSERT_EQ(Triangle::Kind::EQUILATERAL, triangle.getKind());
}

TEST(TriangleTests, testisIsosceles)
{
    Triangle triangle(5,3,3);
    ASSERT_EQ(true, triangle.Triangle::isIsosceles());
}

TEST(TriangleTests, testisEquilateral)
{
    Triangle triangle(3,3,3);
    ASSERT_EQ(true, triangle.Triangle::isEquilateral());
}

//the sides must be in descending order by the request
//here it's not but still construct the triangle
//should add a assert side1 > side2 > side3
TEST(TriangleTests, testConstructor)
{
    Triangle triangle(5,3,4);
    ASSERT_EQ(Triangle::Kind::SCALENE, triangle.getKind());
}