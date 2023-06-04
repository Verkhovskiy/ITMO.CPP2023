#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm> // для алгоритма сортировки

class Point
{
private:
    float x;
    float y;
public:
    Point(float coordX, float coordY): x(coordX), y(coordY) {};
    float distToOrigin() const {
        return sqrt(pow(x,2) + pow(y,2));
    }
    friend std::ostream& operator<< (std::ostream &out, const Point &p) {
        out << "x: " << p.x << ", y: " << p.y;
        return out;
    }
    bool operator< (Point& p) const
    {
        if (distToOrigin() < p.distToOrigin()) return true;
        return false;
    }
};

int main()
{
    std::vector<Point> v;
    v.push_back(Point(1,2));
    v.push_back(Point(10,12));
    v.push_back(Point(21,7));
    v.push_back(Point(4,8));
    std::sort(v.begin(), v.end()); // требуется перегрузка оператора < для // класса Point
    for (auto &point : v)
    std::cout << point << '\n'; // требуется перегрузка оператора << для // класса Point
    return 0;
}