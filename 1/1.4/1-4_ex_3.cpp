#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

ull diplomasNumber(ull w, ull h, ull len) {
    return (len / w) * (len / h);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ull w, h, n;
    cin >> w >> h >> n;
    ull l = 0;
    ull r = max(w, h) * n;
    for (int i = 0; i < 100; i++) {
        ull mid = (l + r) / 2;
        if (diplomasNumber(w, h, mid) < n) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << r;
}