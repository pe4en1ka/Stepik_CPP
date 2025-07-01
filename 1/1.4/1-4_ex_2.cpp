#include <bits/stdc++.h>
using namespace std;
#define ld long double

constexpr long double EPS = 1e-15;
short int k[6];
int n;
ld cx, cy, cd;

ld f(ld x) {
    if (n == 4) {
        short int k4 = k[1], k3 = k[2], k2 = k[3], k1 = k[4], ks = k[5];
        ld x1 = x;
        ld x2 = x * x1;
        ld x3 = x * x2;
        ld x4 = x * x3;
        return k4 * x4 + k3 * x3 + k2 * x2 + k1 * x1 + ks;
    }
    else if (n == 3) {
        short int k3 = k[0], k2 = k[1], k1 = k[2], ks = k[3];
        ld x1 = x;
        ld x2 = x * x1;
        ld x3 = x * x2;
        return k3 * x3 + k2 * x2 + k1 * x1 + ks;
    }
    else if (n == 2) {
        short int k2 = k[0], k1 = k[1], ks = k[1];
        ld x1 = x;
        ld x2 = x * x1;
        return x2 * k2 + x * k1 + ks;
    }
    else if (n == 1) {
        short int k1 = k[0], ks = k[1];
        return x * k1 + ks;
    }
    else {
        return k[0];
    }
}

ld dis(ld x) {
    ld y = f(x);
    return sqrt((cx - x) * (cx - x) + (cy - y) * (cy - y));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> cx >> cy >> cd;
    cin >> n;
    for (int i = 0; i < n + 1; i++) {
        cin >> k[i];
    }
    int x;
    cin >> x;
    ld l = x - cd;
    ld r = x + cd;

    
    for (int i = 0; i < 100; i++) {
        ld mid = (l + r) / 2.0;
        if (dis(mid) < cd) {
            l = mid;
        }
        else {
            r = mid;
        }
    }cout.setf(ios::fixed);
    cout.precision(20);
    cout << (l + r) / 2.0 << '\n';
    cout << f((l + r) / 2.0);
}