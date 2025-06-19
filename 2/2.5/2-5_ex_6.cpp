#include <iostream>
using namespace std;

int main() {
    short int a, b, cnt = 0;
    cin >> a >> b;
    while (a <= b) {
        a *= 3;
        b *= 2;
        cnt++;
    }
    cout << cnt;
}