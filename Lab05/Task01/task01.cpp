#include <iostream>
#include <array>

int sumNegative(int mas[10]) {
    int s = 0;
    for (int i=0; i<10; i++)
    {
        if (mas[i] < 0) {
            s += mas[i];
        }
    }
    return s;
}

int sumPositive(int mas[10]) {
    int s = 0;
    for (int i=0; i<10; i++)
    {
        if (mas[i] > 0) {
            s += mas[i];
        }
    }
    return s;
}

int sumEvenIndex(int mas[10]) {
    int s = 0;
    for (int i=0; i<10; i += 2)
    {
        s += mas[i];
    }
    return s;
}

int sumOddIndex(int mas[10]) {
    int s = 0;
    for (int i=1; i<10; i += 2)
    {
        s += mas[i];
    }
    return s;
}

void findMaxAndMinIndex(int mas[10], int minmax[2]) {
    int min = mas[0];
    int minInd = 0;
    int max = mas[0];
    int maxInd = 0;
    for (int i=0; i<10; i++)
    {
        if (mas[i] < min) {
            min = mas[i];
            minInd = i;
        }
        if (mas[i] > max) {
            max = mas[i];
            maxInd = i;
        }
    }
    minmax[0] = minInd;
    minmax[1] = maxInd;
}

int main() {
    const int n = 10;
    int mas[n];
    for (int i=0; i<n; i++)
    {
        std::cout << "mas[" << i << "]=";
        std::cin >> mas[i];
    }
    int s = 0;
    for (int i=0; i<n; i++)
    {
        s += mas[i];
    }
    double avarage = (double)s / n;
    std::cout << "The sum of the elements is: " << s << std::endl;
    std::cout << "The avarage of the elements is: " << avarage << std::endl;

    std::cout << "The sum of all negative numbers is: " << sumNegative(mas) << std::endl;
    std::cout << "The sum of all positive numbers is: " << sumPositive(mas) << std::endl;
    std::cout << "The sum of all numbers with even index is: " << sumEvenIndex(mas) << std::endl;
    std::cout << "The sum of all numbers with odd index is: " << sumOddIndex(mas) << std::endl;

    int minmaxind[2];
    findMaxAndMinIndex(mas, minmaxind);
    if (minmaxind[0] > minmaxind[1]) {
        int temp = minmaxind[0];
        minmaxind[0] = minmaxind[1];
        minmaxind[1] = temp;
    }
    int mult = 1;
    for (int i = minmaxind[0] + 1; i < minmaxind[1]; i++) {
        mult *= mas[i];
    }
    std::cout << "Multiplication result is: " << mult << std::endl;
}