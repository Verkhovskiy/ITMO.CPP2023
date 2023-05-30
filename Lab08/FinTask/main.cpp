#include <iostream>
#include "time.cpp"

int main()
{
    int hours1, minutes1, seconds1, hours2, minutes2, seconds2;
    std::cout << "Your first time:" << std::endl;
    std::cout << "Hours: ";
    std::cin >> hours1;
    std::cout << "Minutes: ";
    std::cin >> minutes1;
    std::cout << "Seconds: ";
    std::cin >> seconds1;
    std::cout << "Your second time:" << std::endl;
    std::cout << "Hours: ";
    std::cin >> hours2;
    std::cout << "Minutes: ";
    std::cin >> minutes2;
    std::cout << "Seconds: ";
    std::cin >> seconds2;
    Time time1 = Time(hours1, minutes1, seconds1);
    Time time2 = Time(hours2, minutes2, seconds2);
    Time time3;
    time3 = Time::addTime(time1, time2);
    std::cout << "The sum of two times is:" << std::endl;
    time3.print();
}