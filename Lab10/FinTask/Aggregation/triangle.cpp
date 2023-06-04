#include "dot.h"
#include "dot.cpp"
#include <iostream>

class Triangle
{
    private:
        Dot* dots[3];
        double sideLengths[3];
    public:
        Triangle(Dot *first, Dot *second, Dot *third) {
            dots[0] = first;
            dots[1] = second;
            dots[2] = third;
            sideLengths[0] = dots[0]->distanceTo(*dots[1]);
            sideLengths[1] = dots[1]->distanceTo(*dots[2]);
            sideLengths[2] = dots[2]->distanceTo(*dots[0]);
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