#include <iostream>
using namespace std;

struct my_time {
    int day, hour, minute, second;

    my_time(int seconds) {
        if (seconds > 0) {
            day = seconds / 86400;
            hour = seconds / 3600 % 24;
            minute = seconds / 60 % 60;
            second = seconds % 60;
        }
        else {
            day = seconds / 86400 - 1 + !(seconds % 86400);
            seconds = day * (-1) * 86400 + seconds;
            hour = seconds / 3600 % 24;
            minute = seconds / 60 % 60;
            second = seconds % 60;
        }
    }
    my_time()
    : day(0), hour(0), minute(0), second(0)
    {}
};

bool operator < (my_time mt1, my_time mt2) {
    if (mt1.day < mt2.day) {
        return true;
    }
    else if (mt1.day == mt2.day) {
        if (mt1.hour < mt2.hour) {
            return true;
        }
        else if (mt1.hour == mt2.hour) {
            if (mt1.minute < mt2.minute) {
                return true;
            }
            else if (mt1.minute == mt2.minute) {
                if (mt1.second < mt2.second) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

int main() {
    //put yr code here
}