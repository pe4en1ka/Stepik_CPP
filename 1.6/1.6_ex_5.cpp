#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int x ,y, f, k;
    double p;
    cin >> p >> x >> y >> k;
    p = p / 100;\
    f = x * 100 + y;
    while (k != 0) {
        f = f + f * p;
        k--;
    }
    x = trunc(f / 100);
    y = trunc(f - x * 100);
    cout << x << " " << y;
    return 0;
}