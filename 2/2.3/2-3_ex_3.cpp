#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    if (n < 0) {
        n *= -1;
    }
    while (n > 0) {
        cnt  += n % 10;
        n /= 10;
    }
    cout << cnt;
}