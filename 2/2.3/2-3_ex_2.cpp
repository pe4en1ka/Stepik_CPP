#include <bits/stdc++.h>
using namespace std;

int gsd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gsd(b, a % b);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;
    if (c % gsd(a, b) == 0) {
        cout << 1;
    }
    else {
        cout << 0;
    }
}