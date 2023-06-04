#include <iostream>
using namespace std;

class Distance
{
    private:
    int feet;
    float inches;
    public:
    // конструктор по умолчанию
    Distance ( ) : feet (0), inches (0.0) { }
    // конструктор с двумя параметрами
    Distance (int ft, float in) : feet (ft), inches (in) { }
    void getdist()
    {
        cout <<"\nInput feet: ";
        cin >> feet;
        cout <<"\nInput inches: ";
        cin >> inches;
    }
    Distance operator+ (const Distance& d2) const
    {
        int f = feet + d2.feet;
        float i = inches + d2.inches;
        if (i>= 12.0)
        {
            i -= 12.0;
            f++;
        }
        return Distance (f, i);
    }
    Distance operator- (const Distance& d2) const
    {
        int f = feet - d2.feet;
        float i = inches - d2.inches;
        if (i < 0.0)
        {
            i += 12.0;
            f--;
        }
        return Distance (f, i);
    }
    friend std::ostream& operator<< (std::ostream &out, const Distance &dist);
};

std::ostream& operator<< (std::ostream &out, const Distance &dist)
{
    out << dist.feet << "\'-" << dist.inches << "\"\n";
    return out;
}

int main()
{
    Distance dist1, dist2, dist3, dist4;
    cout <<"\nDistance 1:";
    dist1.getdist();
    cout <<"\nDistance 2:";
    dist2.getdist();
    dist3 = dist1 + dist2;
    dist4 = dist1 + dist2 + dist3;
    cout << "\ndist1 = " << dist1;
    cout << "\ndist2 = " << dist2;
    cout << "\ndist3 = " << dist3;
    cout << "\ndist4 = " << dist4;
}