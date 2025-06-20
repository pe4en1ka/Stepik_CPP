#include <iostream>
using namespace std;

struct my_time {
    int day, hour, minute, second;
    void set(int t) {
        if (t > 0) {
            day = t / 86400;
            hour = t / 3600 % 24;
            minute = t / 60 % 60;
            second = t % 60;
        }
        else {
            day = t / 86400 - 1 + !(t % 86400);
            t = day * (-1) * 86400 + t;
            hour = t / 3600 % 24;
            minute = t / 60 % 60;
            second = t % 60;
        }
    }
};

int main() {
    //put yr code here
}