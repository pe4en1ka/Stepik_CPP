#include <bits/stdc++.h>
using namespace std;
#define ll long long

constexpr ll mod = 1e9 + 7;

ll f(ll n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    else {
        return n * f(n - 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m, l;
    cin >> n >> m >> l;
    if (n < m) {
        cout << 0;
        return 0;
    }
    else {
        ll sum = 0;
    }
}