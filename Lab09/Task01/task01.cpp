#include <iostream>
#include <string>
using namespace std;

class DivideByZeroError 
{
    public:
        DivideByZeroError (): message ("Division by zero") { }
        void printMessage () const {cout << message << endl;}
    private:
        string message;
};

float quotient (int numl, int num2) 
{ 
    if (num2 == 0) throw DivideByZeroError();
    return (float)numl / num2;
}

int main () 
{ 
    cout << "Input two inegers to find quotient:\n";
    int number1, number2;
    cin >> number1; cin >> number2;
    try 
    { 
        float result = quotient(number1, number2);
        cout << "Quotient is " << result << endl;
    }
    catch (DivideByZeroError& error) 
    { 
        cout << "Error: ";
        error.printMessage();
        return 1; // завершение программы при ошибке 
    }
    return 0; // нормальное завершение программы 
}