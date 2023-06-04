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
    Time operator+ (Time& b) const
    {
        Time newTime = Time(hours + b.getHours(), minutes + b.getMinutes(), seconds + b.getSeconds());
        newTime.format();
        return newTime;
    }
    Time operator- (Time& b) const
    {
        Time newTime = Time(hours - b.getHours(), minutes - b.getMinutes(), seconds - b.getSeconds());
        newTime.format();
        return newTime;
    }
    Time operator+ (float inHours) const
    {
        int convHours = int (inHours);
        int convMinutes = (inHours - convHours) * 60;
        int convSeconds = (inHours - convHours - (float) convMinutes / 60) * 360;
        Time newTime = Time(hours + convHours, minutes + convMinutes, seconds + convSeconds);
        newTime.format();
        return newTime;
    }
    Time operator- (float inHours) const
    {
        int convHours = int (inHours);
        int convMinutes = (inHours - convHours) * 60;
        int convSeconds = (inHours - convHours - (float) convMinutes / 60) * 360;
        Time newTime = Time(hours - convHours, minutes - convMinutes, seconds - convSeconds);
        newTime.format();
        return newTime;
    }
    bool operator== (Time& b) const
    {
        if (hours == b.getHours() && minutes == b.getMinutes() && seconds == b.getSeconds()) return true;
        return false;
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
    Time originalTime = Time(12, 0, 0);
    std::cout << "Original times is:" << std::endl;
    originalTime.print();
    Time destinationlTime = Time(15, 15, 0);
    std::cout << "Destination times is:" << std::endl;
    destinationlTime.print();
    std::cout << "How many HOURS are between original and destination time?" << std::endl;
    std::cout << "Enter answer (in hours):" << std::endl;
    float hours;
    std::cin >> hours;
    if (originalTime + hours == destinationlTime) {
        std::cout << "The answer is correct!" << std::endl;
    }
    else std::cout << "The answer is wrong! The correct answer is: 3.25" << std::endl;
}