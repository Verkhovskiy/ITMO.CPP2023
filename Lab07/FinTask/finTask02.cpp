#include <iostream>
#include <cmath>

struct Roots
{
    int roots;
    double r1;
    double r2;
};

Roots myRoot(double, double, double);

int main()
{
    double a, b, c;
    std::cout << "Quadratic Equation\nax*x + bx + c = 0\nInput paramerers (format: a b c): ";
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    Roots result = myRoot(a, b, c);
    if (result.roots == 0) std::cout << "Roots not found";
    else if (result.roots == 1) std::cout << "One root x1 = x2 = " << result.r1;
    else std::cout << "Roots are x1 = " << result.r1 << " x2 = " << result.r2;
}

Roots myRoot(double a, double b, double c) {
    Roots r;
    double d = b * b - 4 * a * c;
    if (d == 0) {
        r.roots = 1;
        r.r1 = r.r2 = -b / (2 * a);
        return r;
    }
    if (d > 0) {
        r.roots = 2;
        r.r1 = (-b + sqrt(d)) / (2 * a);
        r.r2 = (-b - sqrt(d)) / (2 * a);
        return r;
    }
    r.roots = 0;
    return r;
};