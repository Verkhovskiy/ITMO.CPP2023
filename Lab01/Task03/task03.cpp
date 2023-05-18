#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "Input the perimeter of the triangle:\n";
    double inpP;
    cin >> inpP;
    double p = inpP / 2;
    double a, b, c;
    a = b = c = inpP / 3;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    cout.precision(3);
    cout << "\nSide     Area" << endl;
    cout << a << "     " << s;
    return 0;
}