#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int n = 1, cnt = 0;
    double s = 0.0, sum = 0.0, square_sum = 0.0;
    while (n != 0) {
        cin >> n;
        sum += n;
        square_sum += n * n;
        cnt++;
    }
    s = sum / (cnt - 1);
    cout << fixed << setprecision(11);
    cout << sqrt((-2 * s * sum + square_sum + s * s * (cnt - 1)) / (cnt - 2));
}