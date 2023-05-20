#include <iostream>

int recSum(int n) {
    if (n == 1) return 5;
    else return n * 5 + recSum(n - 1);
}

int main()
{
    int n;
    std::cout << "Input number: ";
    std::cin >> n;
    std::cout << "Result is: " << recSum(n);
}