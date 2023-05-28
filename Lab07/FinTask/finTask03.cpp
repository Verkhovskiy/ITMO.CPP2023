#include <iostream>
#include <tuple>
#include <cmath>

std::tuple<int, double, double> myRoot(double, double, double);

int main()
{
    double a, b, c;
    std::cout << "Quadratic Equation\nax*x + bx + c = 0\nInput paramerers (format: a b c): ";
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::tuple<int, double, double> result = myRoot(a, b, c);
    if (std::get<0>(result) == 0) std::cout << "Roots not found";
    else if (std::get<0>(result) == 1) std::cout << "One root x1 = x2 = " << std::get<1>(result);
    else std::cout << "Roots are x1 = " << std::get<1>(result) << " x2 = " << std::get<2>(result);
}

std::tuple<int, double, double> myRoot(double a, double b, double c) {
    double d = b * b - 4 * a * c;
    if (d == 0) {
        double result = -b / (2 * a);
        auto r = std::make_tuple(1, result, result);
        return r;
    }
    if (d > 0) {
        double r1 = (-b + sqrt(d)) / (2 * a);
        double r2 = (-b - sqrt(d)) / (2 * a);
        auto r = std::make_tuple(2, r1, r2);
        return r;
    }
    auto r = std::make_tuple(0, 0, 0);
    return r;
};