#include "triangle.cpp"

int main()
{
    Triangle t = Triangle();
    double p = t.getPerimeter();
    double s = t.getArea();
    std::cout << "Triangle perimeter is: " << p << "\nTriangle area is: " << s << std::endl;
    t.printSides();
}