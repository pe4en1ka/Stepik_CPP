#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

ull n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    if (n % 2 == 0 && n != 2) {
        cout << 0;
        return 0;
    }
    for (ull i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}