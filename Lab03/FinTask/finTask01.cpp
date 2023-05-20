#include <iostream>
#include <cctype>
#include <string>
using namespace std;

bool snilsIsValid(string snilsNumber) {
    string filtered = "";
    for (char i : snilsNumber) {
        if (isdigit(i)) filtered += i;
    }
    if (filtered.length() != 11) return false;
    for (int i = 0; i < 9; i++) {
        if (filtered[i] == filtered[i+1] && filtered[i] == filtered[i+2]) return false;
    }
    int contolNumber = (filtered[9] - '0') * 10 + (filtered[10] - '0');
    int checkSum = 0;
    for (int i = 0; i < 9; i++) {
        checkSum += (i + 1) * (filtered[8 - i]  - '0');
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
    getline(cin, snilsNumber);
    if (snilsIsValid(snilsNumber)) cout << "SNILS number is valid";
    else cout << "NOT VALID SNILS NUMBER!";
}