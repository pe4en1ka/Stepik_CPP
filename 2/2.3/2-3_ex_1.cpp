#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int cnt) {
    if (b == 0) {
        return cnt;
    }
    else {
        cnt++;
        return gcd(b, a % b, cnt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b, cnt = 0;
    cin >> a >> b;
    cout << gcd(a, b, cnt);
}