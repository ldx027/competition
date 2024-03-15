#include <iostream>
using namespace std;

class Time
{
public:
    int hour, min;

public:
    Time() {}
    Time(int h, int m) : hour(h), min(m) {}

    void during(Time past)
    {
        Time beg(this->hour, this->min);
        beg.min += past.min;
        beg.hour += past.hour;
        beg.hour += beg.min >= 60 ? 1 : (beg.min < 0 ? -1 : 0);
        beg.min = (beg.min + 60) % 60;
        if (beg.hour >= 24) beg.hour %= 24;
        else if (beg.hour < 0) while(beg.hour < 0) beg.hour += 24;

        *this = beg;
    }

    static Time change(int min, bool past)
    {
        Time rst(min / 60, min % 60);
        if (!past)
        {
            rst.min *= -1;
            rst.hour *= -1;
        }
        return rst;
    }
};


int main()
{
    int s, v;
    cin >> s >> v;

    double needTime = s / (double)v;
    needTime = (needTime == s / v ? needTime : int(needTime) + 1);
    Time pase;
    Time past = Time::change(int(needTime), false);
    Time rst(7, 50);
    rst.during(past);
    printf("%02d:%02d", rst.hour, rst.min);

    return 0;
}