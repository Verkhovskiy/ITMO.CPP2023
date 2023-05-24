#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    int a, b, c;
    int k = 0;
    const int n = 10;
    int mas[n];
    for(int i = 0;i < n ;i++)
    {
        // инициализация операндов случайными числами от 1 до 101
        a = rand() % 10 + 1;
        b = rand() % 10 + 1;
        cout << a << " * " << b << " = ";
        cin >> c;
        mas[i] = c;
        if (a*b != c)
        {
            k++; // операция «инкремент», аналогично: k = k + 1
            cout << "Error! ";
            cout << a << " * " << b << " = " << a * b << endl;
        }
    }
    cout << "\nAll:\n";
    for (int i=0; i<n; i++) {
        cout << mas[i] << endl;
    }
    cout << "Count error: " << k << endl;
    return 0;
}