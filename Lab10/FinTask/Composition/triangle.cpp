#include "dot.h"
#include "dot.cpp"
#include <iostream>

class Triangle
{
    private:
        Dot dots[3];
        double sideLengths[3];
    public:
        Triangle() {
            double x, y;
            std::cout << "*** Input coordinates of the triangle ***" << std::endl;
            std::cout << "First coordinate (Format: x y): ";
            std::cin >> x;
            std::cin >> y;
            dots[0] = Dot(x,y);
            std::cout << "Second coordinate (Format: x y): ";
            std::cin >> x;
            std::cin >> y;
            dots[1] = Dot(x,y);
            std::cout << "Third coordinate (Format: x y): ";
            std::cin >> x;
            std::cin >> y;
            dots[2] = Dot(x,y);
            sideLengths[0] = dots[0].distanceTo(dots[1]);
            sideLengths[1] = dots[1].distanceTo(dots[2]);
            sideLengths[2] = dots[2].distanceTo(dots[0]);
        }
        void printSides() {
            std::cout << "The lengths of triangle sides are: " << std::endl << sideLengths[0] << std::endl << sideLengths[1] << std::endl << sideLengths[2];
        }
        double getPerimeter() {
            return sideLengths[0] + sideLengths[1] + sideLengths[2];
        }
        double getArea() {
            double p = getPerimeter() / 2;
            return sqrt(p * (p - sideLengths[0]) * (p - sideLengths[1]) * (p - sideLengths[2]));
        }
};