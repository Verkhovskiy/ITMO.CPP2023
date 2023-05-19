#include <iostream>
#include <string>
using namespace std;

bool snilsIsValid(string snilsNumber) {
    if (snilsNumber.length() != 11) return false;
    for (int i = 0; i < 9; i++) {
        if (snilsNumber[i] == snilsNumber[i+1] && snilsNumber[i] == snilsNumber[i+2]) return false;
    }
    int contolNumber = (snilsNumber[9] - '0') * 10 + (snilsNumber[10] - '0');
    int checkSum = 0;
    for (int i = 0; i < 9; i++) {
        checkSum += (i + 1) * (snilsNumber[8 - i]  - '0');
    }
    if (checkSum < 100) {
        if (checkSum == contolNumber) return true;
        return false;
    }
    if (checkSum == 100 || checkSum == 101) {
        if (checkSum == 0) return true;
        return false;
    }
    checkSum %= 101;
    if (checkSum < 100) {
        if (checkSum == contolNumber) return true;
        return false;
    }
    if (checkSum == 100) {
        if (checkSum == 0) return true;
        return false;
    }
    return false;
}

int main()
{
    string snilsNumber;
    cout << "Input your SNILS number: ";
    cin >> snilsNumber;
    if (snilsIsValid(snilsNumber)) cout << "SNILS number is valid";
    else cout << "NOT VALID SNILS NUMBER!";
}