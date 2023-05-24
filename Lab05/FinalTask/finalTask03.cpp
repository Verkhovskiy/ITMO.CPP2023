#include <iostream>

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

int transposeSearch(int *k, int n, int key)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        if (k[i] == key)
        {
            if (i == 0)
            return i;
            temp = k[i];
            k[i] = k[i - 1];
            k[i - 1] = temp;
            return i;
        }
    }
    return -1;
}

int main() 
{
    int arraySize;
	std::cout << "How many numbers do you have?\n";
    std::cin >> arraySize;
    int* myArray = new int[arraySize];
    fill_array(myArray, arraySize);
    bool continueSearch = true;
    int result;
    while (continueSearch) {
        int key;
        std::cout << "Input number you want to find: ";
        std::cin >> key;
        result = transposeSearch(myArray, arraySize, key);
        if (result == -1) std::cout << "Number not found\n";
        else std::cout << "Index of the number is " << result << std::endl;
        char response;
	    std::cout << "Do you want to continue search? (y / n): ";
        std::cin >> response;
        if (response == 'n') {
            continueSearch = false;
        }
    }
    return 0;
}