#include <iostream>
#include <cmath>

int myRoot(double, double, double, double&, double&);

int main()
{
    double a, b, c, x1, x2;
    std::cout << "Quadratic Equation\nax*x + bx + c = 0\nInput paramerers (format: a b c): ";
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    int result = myRoot(a, b, c, x1, x2);
    if (result == -1) std::cout << "Roots not found";
    else if (result == 0) std::cout << "One root x1 = x2 = " << x1;
    else std::cout << "Roots are x1 = " << x1 << " x2 = " << x2;
}

int myRoot(double a, double b, double c, double &x1, double &x2) {
    double d = b * b - 4 * a * c;
    if (d == 0) {
        x1 = x2 = -b / (2 * a);
        return 0;
    }
    if (d > 0) {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        return 1;
    }
    return -1;
};