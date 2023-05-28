#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string> 
using json = nlohmann::json;

void sortArray(int a[], int N)
{
    int min = 0; // дл€ записи минимального значени€
    int buf = 0; // дл€ обмена значени€ми
    for (int i = 0; i < N; i++)
    {
        min = i; // номер текущей €чейки, как €чейки с минимальным значением
        // в цикле найдем реальный номер €чейки с минимальным значением
        for (int j = i + 1; j < N; j++) min = (a[j] < a[min]) ? j : min;
        // перестановка этого элемента, помен€в его местами с текущим
        if (i != min)
        {
            buf = a[i];
            a[i] = a[min];
            a[min] = buf;
        }
    }
}

int main()
{    
    std::ifstream input("input.json");
    json unsorted;
    input >> unsorted;
    int N = 0;
    for (int element : unsorted) N += 1;
    int* myArray = new int[N];
    int i = 0;
    for (int element : unsorted) 
    {
        myArray[i] = element;
        i++;
    }
    sortArray(myArray, N);
    json sorted;
    for (int j = 0; j < N; j++) {
        std::string key = std::to_string(j);
        sorted[key] = myArray[j];
    }
    std::ofstream output("output.json");
    output << std::setw(4) << sorted << std::endl;
}