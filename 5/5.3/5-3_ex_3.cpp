#include <iostream>
using namespace std;

int main() {
    unsigned long long n;
    cin >> n;
    if (n % 3 == 0) {
        cout << n / 3;
    }
    else if (n % 3 == 1) {
        cout << (n + 2 * 18446744073709551615) / 3;
    }
    else {
        cout << (n + 18446744073709551615) / 3;
    }
}