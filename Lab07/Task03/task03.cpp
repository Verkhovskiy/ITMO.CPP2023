#include <iostream>
#include <windows.h>
using namespace std;

struct Distance
{
    int feet;
    double inches;
    void ShowDist()
    {
        cout << feet << "\'-" << inches << "\"\n";
    }
};

Distance AddDist(const Distance &d1, const Distance &d2)
{
    Distance d;
    d.feet = d1.feet + d2.feet;
    d.inches = d1.inches + d2.inches;
    if (d.inches>= 12.0 )
    {
        d.inches -= 12.0;
        d.feet++;
    }
    return d;
}

Distance InputDist()
{
    Distance d;
    cout << "Input feet: ";
    cin >> d.feet;
    cout << "Input inches: ";
    cin >> d.inches;
    return d;
}

int main()
{
    int n;
    cout << "Input distances array size: " ;
    cin >> n;
    Distance * masDist = new Distance[n];
    for (int i = 0; i<n; i++)
    {
        masDist[i] = InputDist();
    }
    for (int i = 0; i<n; i++)
    {
        masDist[i].ShowDist();
    }
    Distance sum = masDist[0];
    for (int i = 0; i < n - 1; i++)
    {
        sum = AddDist(sum, masDist[i + 1]);
    }
    cout << "Sum of distances:" << endl;
    sum.ShowDist();
    delete[] masDist;
}