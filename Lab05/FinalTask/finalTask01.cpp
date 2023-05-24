#include <iostream>

void fill_array(int Arr[], int N);
int sumAll(int mas[], int arrayLength);
double avarage(int mas[], int arrayLength);
int sumNegative(int mas[], int arrayLength);
int sumPositive(int mas[], int arrayLength);
int sumEvenIndex(int mas[], int arrayLength);
int sumOddIndex(int mas[], int arrayLength);
void findMaxAndMinIndex(int mas[], int N, int minmax[2]);
int multBetweenMinMax(int mas[], int arrayLength);

int main() {
    int arraySize;
	std::cout << "How many numbers do you have?\n";
    std::cin >> arraySize;
    int* myArray = new int[arraySize];
    fill_array(myArray, arraySize);
    std::cout << "The sum of all numbers is: " << sumAll(myArray, arraySize) << std::endl;
    std::cout << "The avarage of the elements is: " << avarage(myArray, arraySize) << std::endl;
    std::cout << "The sum of all negative numbers is: " << sumNegative(myArray, arraySize) << std::endl;
    std::cout << "The sum of all positive numbers is: " << sumPositive(myArray, arraySize) << std::endl;
    std::cout << "The sum of all numbers with even index is: " << sumEvenIndex(myArray, arraySize) << std::endl;
    std::cout << "The sum of all numbers with odd index is: " << sumOddIndex(myArray, arraySize) << std::endl;
    std::cout << "Multiplication result of numbers between MIN and MAX is: " << multBetweenMinMax(myArray, arraySize) << std::endl;
    delete []myArray;
}

void fill_array(int Arr[], int N)
{
	for(int i = 0; i < N; i++)
	{
        int curNumber;
		std::cout << "Input your number #" << i + 1 <<"\n";
        std::cin >> curNumber;
        Arr[i] = curNumber;
	}
}

int sumAll(int mas[], int arrayLength) {
    int s = 0;
    for (int i = 0; i < arrayLength; i++)
    {
        s += mas[i];
    }
    return s;
}

double avarage(int mas[], int arrayLength) {
    int s = 0;
    for (int i = 0; i < arrayLength; i++)
    {
        s += mas[i];
    }
    double avarage = (double)s / arrayLength;
    return avarage;
}

int sumNegative(int mas[], int arrayLength) {
    int s = 0;
    for (int i = 0; i < arrayLength; i++)
    {
        if (mas[i] < 0) {
            s += mas[i];
        }
    }
    return s;
}

int sumPositive(int mas[], int arrayLength) {
    int s = 0;
    for (int i = 0; i < arrayLength; i++)
    {
        if (mas[i] > 0) {
            s += mas[i];
        }
    }
    return s;
}

int sumEvenIndex(int mas[], int arrayLength) {
    int s = 0;
    for (int i = 0; i < arrayLength; i += 2)
    {
        s += mas[i];
    }
    return s;
}

int sumOddIndex(int mas[], int arrayLength) {
    int s = 0;
    for (int i = 1; i < arrayLength; i += 2)
    {
        s += mas[i];
    }
    return s;
}

void findMaxAndMinIndex(int mas[], int N, int minmax[2]) {
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

int multBetweenMinMax(int mas[], int arrayLength) {
    int minmaxind[2];
    findMaxAndMinIndex(mas, arrayLength, minmaxind);
    if (minmaxind[0] > minmaxind[1]) {
        int temp = minmaxind[0];
        minmaxind[0] = minmaxind[1];
        minmaxind[1] = temp;
    }
    int mult = 1;
    for (int i = minmaxind[0] + 1; i < minmaxind[1]; i++) {
        mult *= mas[i];
    }
    return mult;
}