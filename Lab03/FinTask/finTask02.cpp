#include <iostream> 
#include <cmath>

double cubeRoot(double a) {
    return pow(a, 1.0/3);
}

double cubeRootIter(double a) {
    double x, x1;
    x = 1;
    do {
        x1 = x;
        x = (a / (x1 * x1) + 2 * x1) / 3;
    }
    while (abs(x-x1) > 0.00001);
    return x;
}

int main()
{
    double num;
    std::cout << "Input number: ";
    std::cin >> num;
    std::cout << "Result with 'cubeRoot' function: " << cubeRoot(num) << std::endl;
    std::cout << "Result with 'cubeRootIter' function: " << cubeRootIter(num) << std::endl;
}