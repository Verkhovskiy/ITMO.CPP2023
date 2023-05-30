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
    static Time addTime(Time a, Time b) {
        Time newTime = Time(a.getHours() + b.getHours(), a.getMinutes() + b.getMinutes(), a.getSeconds() + b.getSeconds());
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
        minutes = m;
    }
    int getMinutes() {
        return minutes;
    }
    void setSeconds(int s) {
        seconds = s;
    }
    int getSeconds() {
        return seconds;
    }

    private:
    int hours;
    int minutes;
    int seconds;
};