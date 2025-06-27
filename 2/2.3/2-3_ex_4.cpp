#include <iostream>
using namespace std;

int main() {
    int year, cnt;
    cin >> year;
    do {
        year += 1;
        int tmp = year;
        cnt = 0;
        while (tmp > 0) {
            cnt  += tmp % 10;
            tmp /= 10;
        }
    } while (cnt != 13);
    cout << year;
}