#include <iostream>
#include <string>
using namespace std;

bool Input(int &a, int &b) {
    std::cout << "Input numbers (format: a b): ";
    std::cin >> a;
    std::cin >> b;
    if (a < 0 || b < 0) return false;
    return true;
}

int main()
{
    int a, b;
    if(Input(a,b)== false) // if(!Input(a,b))
    {
        cerr << "error";
        return 1;
    }
    int s = a + b;
    return 0;
}