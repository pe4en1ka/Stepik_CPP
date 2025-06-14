#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    while (n <= 10000000) {
        n *= 2;
        cnt++;
    }
    cout << n << " " << cnt;
}
