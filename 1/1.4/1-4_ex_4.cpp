#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

ull copiesNumber(ull x, ull y, ull T) {
    return 1 + T / x + T / y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ull N, x, y;
    cin >> N >> x >> y;
    ull l = 0;
    ull r = N * max(x, y);
    for (int i = 0; i < 100; i++) {
        ull mid = (l + r) / 2;
        if (copiesNumber(x, y, mid) < N) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << r + min(x, y);
}