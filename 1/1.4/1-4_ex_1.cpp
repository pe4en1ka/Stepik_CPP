#include <bits/stdc++.h>
using namespace std;
#define ld long double

constexpr long double EPS = 1e-15;
short int k[6];

long double f(int n, ld x) {
    if (n == 5) {
        short int k5 = k[0], k4 = k[1], k3 = k[2], k2 = k[3], k1 = k[4], ks = k[5];
        ld x1 = x;
        ld x2 = x * x1;
        ld x3 = x * x2;
        ld x4 = x * x3;
        ld x5 = x * x4;
        return k5 * x5 + k4 * x4 + k3 * x3 + k2 * x2 + k1 * x1 + ks;
    }
    else if (n == 3) {
        short int k3 = k[0], k2 = k[1], k1 = k[2], ks = k[3];
        ld x1 = x;
        ld x2 = x * x1;
        ld x3 = x * x2;
        return k3 * x3 + k2 * x2 + k1 * x1 + ks;
    }
    else {
        short int k1 = k[0], ks = k[1];
        cin >> k1 >> ks;
        return x * k1 + ks;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n + 1; i++) {
        cin >> k[i];
    }
    ld l = -10.0;
    ld r = 10.0;  //ld r = 0.9174885834;
    for (int i = 0; i < 100; i++) {
        ld mid = (l + r) / 2.0;
        if (f(n, mid) < 0.0) {
            l = mid;
        }
        else {
            r = mid;
        }
    }cout.setf(ios::fixed);
    cout.precision(16);
    cout << (l + r) / 2.0 << '\n';
    cout << f(n, (l + r) / 2.0);
}