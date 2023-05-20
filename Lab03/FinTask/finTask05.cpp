#include <iostream>
#include <string>
using namespace std;

string toBinary(int num, string result = "") {
    if (num > 0) {
        if (num%2 == 0) return toBinary(num/2, "0" + result);
        else return toBinary(num/2, "1" + result);
    }
    else return result;
}

int main()
{
    int n;
    cout << "Input number: ";
    cin >> n;
    cout << "In binary system: " << toBinary(n);
}