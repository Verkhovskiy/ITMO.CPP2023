#include <iostream> 
#include <cmath>
#include <string>

double triangleArea(double a) {
    return sqrt(3)/4*a*a;
}

double triangleArea(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main()
{
    char triangleType;
    std::cout << "What type of triangle (e - equilateral, s - scalene): ";
    std::cin >> triangleType;
    if (triangleType == "e"[0]) {
        double a;
        std::cout << "Input the side length of the triangle: ";
        std::cin >> a;
        std::cout << "The triangle area is: " << triangleArea(a) << std::endl;
    }
    else if (triangleType == "s"[0]) {
        double a, b, c;
        std::cout << "Input the length for all sides of the triangle (format: a b c): ";
        std::cin >> a;
        std::cin >> b;
        std::cin >> c;
        std::cout << "The triangle area is: " << triangleArea(a, b, c) << std::endl;
    }
}