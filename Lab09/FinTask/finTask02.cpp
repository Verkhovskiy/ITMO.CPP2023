#include <string>
#include <iostream>

class Time
{
    public:
    Time() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    };
    Time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
        format();
    };
    void format() {
        while (seconds >= 60) {
            seconds -= 60;
            minutes ++;
        }
        while (seconds < 0) {
            seconds += 60;
            minutes --;
        }
        while (minutes >= 60) {
            minutes -= 60;
            hours ++;
        }
        while (seconds < 0) {
            seconds += 60;
            minutes --;
        }
    }
    void print() {
        std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
    }
    Time addTime(Time b) {
        Time newTime = Time(hours + b.getHours(), minutes + b.getMinutes(), seconds + b.getSeconds());
        newTime.format();
        return newTime;
    }
    void setHours(int h) {
        hours = h;
    }
    int getHours() {
        return hours;
    }
    void setMinutes(int m) {
        if (m >= 60) throw ExTimeFormat("minutes");
        minutes = m;
    }
    int getMinutes() {
        return minutes;
    }
    void setSeconds(int s) {
        if (s >= 60) throw ExTimeFormat("seconds");
        seconds = s;
    }
    int getSeconds() {
        return seconds;
    }

    class ExTimeFormat
    {
        public:
            ExTimeFormat (std::string v): value(v) { }
            void printMessage () const {std::cout << "Number of " << value << " is more than or equals to 60" << std::endl;}
        private:
            std::string value;
    };

    private:
    int hours;
    int minutes;
    int seconds;
};

int main()
{
    int hours, minutes, seconds;
    std::cout << "Enter time:" << std::endl;
    std::cout << "Hours: ";
    std::cin >> hours;
    std::cout << "Minutes: ";
    std::cin >> minutes;
    std::cout << "Seconds: ";
    std::cin >> seconds;
    try
    {
        Time time = Time();
        time.setHours(hours);
        time.setMinutes(minutes);
        time.setSeconds(seconds);
        std::cout << "The times is:" << std::endl;
        time.print();
    }
    catch(Time::ExTimeFormat error)
    {
        std::cout << "Error: ";
        error.printMessage();
    }
}