#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double coords[10];
    cout << "Input first vertex coordinate (Format: x y):\n";
    cin >> coords[0];
    cin >> coords[1];
    cout << "Input second vertex coordinate (Format: x y):\n";
    cin >> coords[2];
    cin >> coords[3];
    cout << "Input third vertex coordinate (Format: x y):\n";
    cin >> coords[4];
    cin >> coords[5];
    cout << "Input fourth vertex coordinate (Format: x y):\n";
    cin >> coords[6];
    cin >> coords[7];
    cout << "Input fifth vertex coordinate (Format: x y):\n";
    cin >> coords[8];
    cin >> coords[9];
    double s = abs( coords[0] * coords[3] + coords[2] * coords[5] + coords[4] * coords[7] + coords[6] * coords[9] + coords[8] * coords[1] -
                    coords[2] * coords[1] - coords[4] * coords[3] - coords[6] * coords[5] - coords[8] * coords[7] - coords[0] * coords[9]) / 2;
    cout << "\nHexagon area is: " << s;
    return 0;
}