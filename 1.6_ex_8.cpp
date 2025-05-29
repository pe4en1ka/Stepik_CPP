#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    double x, a, s = 0.0;
    cin >> n >> x;
    n++;
    while (n != 0) {
        cin >> a;
        if (n == 1) {
            s += a;
        }
        else {
            s = (s + a) * x;
        }
        n--;
    }
    cout << s;
}