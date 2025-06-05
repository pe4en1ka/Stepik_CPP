#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, x1, x2;
    cin >> a >> b >> c;
    if (b * b - 4 * a * c > 0) {
        x1 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        x2 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        if (x1 > x2) {
            cout << x2 << " " << x1;
        }
        else {
            cout << x1 << " " << x2;
        }
    }
    else if (b * b - 4 * a * c < 0) {
        return 0;
    }
    else {
        x1 = (-b / (2 * a));
        cout << x1;
    }
    return 0;
}