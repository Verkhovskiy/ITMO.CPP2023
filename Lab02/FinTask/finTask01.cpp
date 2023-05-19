#include <iostream>
#include <string>

bool isPrime(int num, int divider = 2) {
    if (num == divider) return true;
    if (num % divider == 0 || num < 2) return false;
    if (divider > num / 2) return true;
    return isPrime(num, divider + 1);
}

int main()
{
    int number;
    int position = 1;
    std::cout << "Input number: ";
    std::cin >> number;
    if (isPrime(number)) {
        for (int i = 0; i < number; i++) {
            if (isPrime(i)) position++;
        }
        if (isPrime(position)) std::cout << "The number IS SUPERPRIME!";
        else std::cout << "The number is not a superprime";
    }
    else std::cout << "The number is not a superprime";
}