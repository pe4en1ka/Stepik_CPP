#include <bits/stdc++.h>
using namespace std;
#define ll long long

constexpr int m = 1e9 + 7;

ll Mfastpow(ll a, ll n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 1) {
        return (a * Mfastpow(a, n - 1)) % m;
    }
    ll tmp = Mfastpow(a, n / 2);
    return (tmp * tmp) % m;
}

ll Mmult

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

}