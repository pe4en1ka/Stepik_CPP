#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    double n = 1.0, sum = 0, cnt = 0;
    while (n != 0) {
        cin >> n;
        sum += n;
        cnt++;
    }
    cout << fixed << setprecision(11);
    cout << sum / (cnt - 1);
    return 0;
}