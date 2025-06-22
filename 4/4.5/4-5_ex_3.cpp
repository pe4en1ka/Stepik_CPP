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
    int covert_to_sec() {
        return day * 86400 + hour * 3600 + minute * 60 + second;
    }
};

my_time operator - (my_time mt1, my_time mt2) {
    my_time result;
}

int main() {
    //put yr code here
}