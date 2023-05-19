#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    double coins[] = {0.01, 0.05, 0.1, 0.5, 1, 2, 5, 10};
    sort(begin(coins), end(coins), greater<double>());
    int coinsNum = sizeof(coins) / sizeof(double);
    double sum;
    cout << "Input ammount: ";
    cin >> sum;
    cout << "The coins you need are:" << endl;
    for (int i = 0; i < coinsNum; i++) {
        while (sum >= coins[i]) {
            sum -= coins[i];
            cout << coins[i] << endl;
        }
    }
}