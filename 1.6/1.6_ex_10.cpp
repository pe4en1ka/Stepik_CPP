#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, x1, x2;
    cin >> a >> b >> c;
    if (b * b - 4 * a * c > 0 && a != 0) {
        x1 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        x2 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        if (x1 > x2) {
            cout << 2 << " " << x2 << " " << x1;
        }
        else {
            cout << 2 << " " << x1 << " " << x2;
        }
    }
    else if (b * b - 4 * a * c < 0 || a == 0 && b == 0 && c != 0) {
        cout << 0;
    }
    else if (a == 0 && b == 0 && c == 0) {
        cout << 3;
    }
    else if (a == 0 && b != 0 && c != 0) {
        x1 = -c / b;
        cout << 1 << " " << x1;
    }
    else {
        x1 = (-b / (2 * a));
        cout << 1 << " " << x1;
    }
    return 0;
}