#include <iostream>
using namespace std;

struct Time
{
    int hours;
    int minutes;
    int seconds;
    void writeTime() {
        cout << hours << " hours, " << minutes << " minutes, " << seconds << " seconds.";
    }
    int countSeconds()
    {
        return hours * 360 + minutes * 60 + seconds;
    }
    Time addTime(const Time &t2) {
        Time t;
        t.hours = hours + t2.hours;
        t.minutes = minutes + t2.minutes;
        if (t.minutes >= 60)
        {
            t.minutes -= 60;
            t.hours++;
        }
        t.seconds = seconds + t2.seconds;
        if (t.seconds >= 60)
        {
            t.seconds -= 60;
            t.minutes++;
        }
        return t;
    }
    Time subtrTime(const Time &t2) {
        Time t;
        t.hours = hours - t2.hours;
        t.minutes = minutes - t2.minutes;
        if (t.minutes < 0)
        {
            t.minutes += 60;
            t.hours--;
        }
        t.seconds = seconds - t2.seconds;
        if (t.seconds < 0)
        {
            t.seconds += 60;
            t.minutes--;
        }
        return t;
    }
};

Time InputTime()
{
    Time t;
    cout << "Input hours: ";
    cin >> t.hours;
    cout << "Input minutes: ";
    cin >> t.minutes;
    cout << "Input seconds: ";
    cin >> t.seconds;
    return t;
}

int main()
{
    Time t1 = InputTime();
    string comand;
    while (comand != "end") {
        cout << "\nWhat do you want to do?\nShow time - write \"show\"\nShow seconds - write \"seconds\"\nAdd time - write \"add\"\nSubtract time - write \"subtr\"\nExit - write \"end\"\n\nInput comand: ";
        cin >> comand;
        if (comand == "show") {
            cout << endl;
            t1.writeTime();
            cout << endl;
        }
        if (comand == "seconds") {
            cout << endl << t1.countSeconds() << " seonds" << endl;
        }
        if (comand == "add") {
            Time t2 = InputTime();
            t1 = t1.addTime(t2);
        }
        if (comand == "subtr") {
            Time t2 = InputTime();
            t1 = t1.subtrTime(t2);
        }
    }
}