#include <iostream>
using namespace std;

int main() {
    double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    cout << (d * e - b * f) / (d * a - b * c) << " " << (c * e - a * f) / (c * b - a * d);
    return 0;
}