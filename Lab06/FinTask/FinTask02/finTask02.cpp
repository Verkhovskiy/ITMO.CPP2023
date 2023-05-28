#include <iostream>
#include <fstream>
#include <string>

void sortArray(int a[], int N)
{
    int min = 0; // для записи минимального значения
    int buf = 0; // для обмена значениями
    for (int i = 0; i < N; i++)
    {
        min = i; // номер текущей ячейки, как ячейки с минимальным значением
        // в цикле найдем реальный номер ячейки с минимальным значением
        for (int j = i + 1; j < N; j++) min = ( a[j] < a[min] ) ? j : min;
        // перестановка этого элемента, поменяв его местами с текущим
        if (i != min)
        {
            buf = a[i];
            a[i] = a[min];
            a[min] = buf;
        }
    }
}

int main() {
    std::ofstream out ("lists.txt", std::ios::out);
    if (!out) {
        std::cout << "Can't open file\n";
        return 1;
    }
    const int N = 10;
    int a[N]={ 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
    out << "Original list:\n";
    for (int i = 0; i < N - 1; i++) {
        out << a[i];
        out << ", ";
    }
    out << a[N-1];
    out << "\n";
    sortArray(a, N);
    out << "Sorted list:\n";
    for (int i = 0; i < N - 1; i++) {
        out << a[i];
        out << ", ";
    }
    out << a[N-1];
    out.close();
}