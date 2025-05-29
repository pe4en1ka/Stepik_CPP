#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int x ,y, f;
    double p;
    cin >> p >> x >> y;
    p = p / 100;\
    f = x * 100 + y;
    f = f + f * p;
    x = trunc(f / 100);
    y = trunc(f - x * 100);
    cout << x << " " << y;
    return 0;
}