#include <iostream>
using namespace std;
class structs {
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

    my_time(int d, int h, int min, int sec)
        : day(d), hour(h), minute(min), second(sec) {}

    [[nodiscard]] int covert_to_sec() const {
        return day * 86400 + hour * 3600 + minute * 60 + second;
    }

    };
    my_time operator - (my_time mt1, my_time mt2) const {
        return my_time(mt1.covert_to_sec() - mt2.covert_to_sec());
    }
    struct house {


    int floors;
    int residents;
    my_time build_time;

    house (int fl, int res, my_time bt)
        : floors(fl), residents(res), build_time(bt) {}
    };
    bool operator == (house a, house b) const {
        
    }
};



int main() {

}