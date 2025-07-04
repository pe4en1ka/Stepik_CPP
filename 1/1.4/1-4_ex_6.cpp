#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

constexpr ull MAXN = 10500;
ull n, k;
ull a[MAXN];

ull ropes(ull len) {
    ull amnt = 0;
    for (int i = 0; i < n; i++) {
        amnt += a[i] / len;
    }
    return amnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ull l = 0;
    ull r = 1e+9 + 1;
    ull amnt = 0;
    for (int i = 0; i < n; i++) {
        amnt += a[i];
    }
    if (amnt < k) { cout << 0; return 0; }
    for (int i = 0; i < 100; i++) {
        ull mid = (l + r) / 2;
        if (ropes(mid) < k) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << r - 1;
}