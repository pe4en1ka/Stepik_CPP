#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

constexpr int m = 1e6 + 3;
int n;
ull mult;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    if (n == 1) {
        mult = 1 % m;
    }
    else if (n >= m) {
        mult = 0;
    }
    else {
        mult = 1;
        for (int i = 2; i <= n; i++) {
            mult = (mult % m * i % m) % m;
        }
    }
    cout << mult;
}