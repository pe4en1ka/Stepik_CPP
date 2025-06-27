#include <iostream>
using namespace std;

int main() {
    unsigned long long n, x;
    cin >> n;
    if (n % 3 == 0) {
        x = n / 3;
    }
    else if (n % 3 == 2) {
        x = 6148914691236517205 + ((n + 1) / 3);
    }
    else {
        x = 12297829382473034410 + ((n + 2) / 3);
    }
    cout << x;
}