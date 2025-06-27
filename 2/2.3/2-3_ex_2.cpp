#include <iostream>
using namespace std;

int main() {
    int pre, now, cnt = 2;
    cin >> pre >> now;
    while (pre != now) {
        pre = now;
        cin >> now;
        cnt++;
    }
    cout << cnt;
}