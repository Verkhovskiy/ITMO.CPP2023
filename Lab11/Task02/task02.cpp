#include <iostream>
using namespace std;

class Distance
{
    private:
        int feet;
        float inches;
        const float MTF;
    public:
        Distance ( ) : feet (0), inches (0.0), MTF (3.280833F) { }
        Distance (int ft, float in) : feet (ft), inches (in), MTF (3.280833F) { }
        void getdist()
        {
            cout <<"\nInput feet: ";
            cin >> feet;
            cout <<"\nInput inches: ";
            cin >> inches;
        }
        Distance (float meters) : MTF (3.280833F)
        {
            float fltfeet = MTF * meters; // перевод в футы
            feet = int (fltfeet); // число полных футов
            inches = 12 * (fltfeet - feet); // остаток - это дюймы
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
        operator float( ) const
        {
            float fracfeet = inches / 12;
            fracfeet += static_cast<float>( feet );
            return fracfeet / MTF;
        }
};

std::ostream& operator<< (std::ostream &out, const Distance &dist)
{
    out << dist.feet << "\'-" << dist.inches << "\"\n";
    return out;
}

int main()
{
    Distance dist1 = 2.35F;
    float mtrs;
    mtrs = static_cast<float>(dist1);
    cout << mtrs << endl;
    mtrs = dist1;
    cout << mtrs << endl;
}