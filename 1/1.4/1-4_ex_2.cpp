#include <bits/stdc++.h>
using namespace std;
#define ld long double

constexpr long double EPS = 1e-15;
short int k[6];
int n;
ld cx, cy, cd;

ld f(ld x) {
    if (n == 4) {
        return k[0]*x*x*x*x + k[1]*x*x*x + k[2]*x*x + k[3]*x + k[4];
    }
    else if (n == 3) {
        return k[0]*x*x*x + k[1]*x*x + k[2]*x + k[3];
    }
    else if (n == 2) {
        return k[0]*x*x + k[1]*x + k[2];
    }
    else if (n == 1) {
        return k[0]*x + k[1];
    }
    else {
        return k[0];
    }
}

ld dis(ld x) {
    ld y = f(x);
    return (cx - x) * (cx - x) + (cy - y) * (cy - y);
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
        if (dis(mid) < cd * cd) {
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