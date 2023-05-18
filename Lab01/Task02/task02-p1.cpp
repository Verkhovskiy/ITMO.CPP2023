#include <iostream>
using namespace std;
int main()
{ 
    double a, b;
    cout << "Input a and b:\n";
    cin >> a; // ввод с клавиатуры значения a
    cin >> b; // ввод с клавиатуры значения b
    int x = a / b; // вычисление значения x
    double y = a / b;
    cout << sizeof(a/b) << " " << sizeof(x) << " " <<  sizeof(y) << endl;
    cout.precision(3);
    cout << "\nx = " << y << endl; //вывод результата на экран
    return 0;
}