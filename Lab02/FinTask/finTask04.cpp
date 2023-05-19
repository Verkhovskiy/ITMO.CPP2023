#include <iostream> 
#include <ctime>
#include <cmath>
using namespace std;

int main()
{
    srand(time(NULL));
    int targetX = rand() % 11;
    int targetY = rand() % 11;
    int score = 0;
    int numShots = 0;
    while (score < 50) {
        int shotX, shotY, distX, distY;
        cout << "Choose where to shoot (Format: x y , where x and y are in range [0, 10]):" << endl;
        cin >> shotX;
        cin >> shotY;
        if (rand() % 10 > 8) {
            shotX += rand() % 5 - 2;
            shotY += rand() % 5 - 2;
            cout << "Your hand trembled, you shot at X: " << shotX << " Y: " << shotY << endl;
        }
        distX = abs(targetX - shotX);
        distY = abs(targetY - shotY);
        if (distX * distX + distY * distY <= 1) {
            cout << "Great shot! You scored 10 points!" << endl;
            score += 10;
        }
        else if (distX * distX + distY * distY <= 4) {
            cout << "Good, but could be better! You scored 5 points" << endl;
            score += 5;
        }
        else if (distX * distX + distY * distY <= 9) {
            cout << "You nearly missed, but scored 1 point" << endl;
            score += 1;
        }
        else cout << "You missed!" << endl;
        cout << "Your current score is: " << score << "\n" << endl;
        numShots++;
    }
    cout << "GAME OVER!" << endl;
    cout << "Your shot " << numShots << " times." << endl;
    if (numShots < 8) {
        cout << "You are a sniper!" << endl;
    }
    if (numShots < 14) {
        cout << "You are a good shooter!" << endl;
    }
    else {
        cout << "You need more practice!" << endl;
    }
}