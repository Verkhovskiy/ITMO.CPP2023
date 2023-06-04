#include "triangle.cpp"

int main()
{
    Dot a = Dot(0, 0);
    Dot b = Dot(-10, -5);
    Dot c = Dot(10, -5);
    Triangle t = Triangle(a, b, c);
    double p = t.getPerimeter();
    double s = t.getArea();
    std::cout << "Triangle perimeter is: " << p << "\nTriangle area is: " << s << std::endl;
    t.printSides();
}