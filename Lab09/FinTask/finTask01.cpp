#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Triangle
{
    public:
    Triangle(int a, int b, int c) {
        int sides[3] = {a, b, c};
        for (int i = 0; i < 3; i++)  {
            if (sides[i] > sides[(i + 1) % 3] + sides[(i + 2) % 3]) {
                throw ExSide(i + 1);
            }
        }
        sideA = a;
        sideB = b;
        sideC = c;
    }    
    double triangleArea() {
        double p = (sideA + sideB + sideC) / 2;
        return sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
    }
    class ExSide
    {
        public:
            ExSide (int s): side (s) { }
            void printMessage () const {cout << "Side " << side << " is longer than the sum of two other sides" << endl;}
        private:
            int side;
    };
    private:
        int sideA;
        int sideB;
        int sideC;
};

int main () 
{ 
    cout << "Input three sides of a triangle (Format: a b c): ";
    int s1, s2, s3;
    cin >> s1;
    cin >> s2;
    cin >> s3;
    try 
    { 
        Triangle t = Triangle(s1, s2, s3);
        cout << "Triangle area is: " << t.triangleArea() << endl;
    }
    catch (Triangle::ExSide& error) 
    { 
        cout << "Error: ";
        error.printMessage();
        return 1;
    }
    return 0;
}