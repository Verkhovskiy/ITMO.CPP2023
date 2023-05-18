#include <iostream>
using namespace std;

int main()
{
    string name;
    cout << "Input your name\n";
    double a, b;
    cout << "Input a and b:\n";
    cin >> a;
    cin >> name;
    cin >> b;
    double x = a / b;
    cout << "\nx = " << x << endl;
    cout << "Hi, " << name << "!\n";
    return 0;
}