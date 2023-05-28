#include <iostream>
#include <windows.h>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

using Tuple = tuple<string, int, double>;
using reducedTuple = tuple<string, double>;

Tuple funtup(string s, int a, double d)
{
    s.append("!");
    return make_tuple(s, a, d*10);
}

Tuple tupleFunction(Tuple t)
{
    string s = std::get<0>(t) + " additional info";
    int a = std::get<1>(t) + 3;
    double d = std::get<2>(t) / 2.5;
    return make_tuple(s, a, d);
}

reducedTuple reduceTupleFunction(Tuple t)
{
    string s = std::get<0>(t) + " " + to_string(std::get<1>(t));
    double d = std::get<2>(t) * 2.5;
    return make_tuple(s, d);
}

void printTupleOfThree(Tuple t)
{
    cout << "("
    << std::get<0>(t) << ", "
    << std::get<1>(t) << ", "
    << std::get<2>(t) << ")" << endl;
}

void printTupleOfThree(reducedTuple t)
{
    cout << "("
    << std::get<0>(t) << ", "
    << std::get<1>(t) << ")" << endl;
}

int main()
{
    vector<string> v1{ "one", "two", "three", "four", "five", "six" };
    vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
    vector<double> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
    auto t0 = make_tuple(v1[0], v2[0], v3[0]);
    auto t1 = funtup(v1[1], v2[1], v3[1]);
    auto t2 = tupleFunction(t1);
    auto t3 = reduceTupleFunction(t2);
    printTupleOfThree(t0);
    printTupleOfThree(t1);
    printTupleOfThree(t2);
    printTupleOfThree(t3);
    return 0;
}