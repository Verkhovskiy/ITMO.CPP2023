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
            metersToFeetInches(meters, feet, inches);
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
        Distance operator+ (float d2) const
        {
            int d2Feet;
            float d2Inches;
            metersToFeetInches(d2, d2Feet, d2Inches);
            int f = feet + d2Feet;
            float i = inches + d2Inches;
            if (i>= 12.0)
            {
                i -= 12.0;
                f++;
            }
            return Distance (f, i);
        }
        Distance operator- (float d2) const
        {
            int d2Feet;
            float d2Inches;
            metersToFeetInches(d2, d2Feet, d2Inches);
            int f = feet - d2Feet;
            float i = inches - d2Inches;
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
        void metersToFeetInches (float meters, int &convertedFeet, float &convertedInches) const
        {
            float fltfeet = MTF * meters;
            convertedFeet = int (fltfeet);
            convertedInches = 12 * (fltfeet - convertedFeet);
        }
};

std::ostream& operator<< (std::ostream &out, const Distance &dist)
{
    out << dist.feet << "\'-" << dist.inches << "\"\n";
    return out;
}

int main()
{
    Distance dist1 = Distance(2.35F);
    float mtrs;
    mtrs = dist1 + 2.8F;
    cout << mtrs << endl;
    mtrs = 2.8F + dist1;
    cout << mtrs << endl;
}