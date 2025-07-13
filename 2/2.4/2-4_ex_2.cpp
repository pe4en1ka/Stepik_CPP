#include <bits/stdc++.h>
using namespace std;
#define ll long long

constexpr int m = 1e9 + 7;

ll Mfastpow(ll a, ll n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 1) {
        return ((a * Mfastpow(a, n - 1)) % m + m) % m;
    }
    ll tmp = Mfastpow(a, n / 2);
    return ((tmp * tmp) % m + m) % m;
}

ll Mmult(ll a, ll b) {
    return ((a % m * b % m) % m + m) % m;}

ll Mdiv(ll a, ll b) {
    return Mmult(a, Mfastpow(b, m - 2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ab = Mdiv(a, b);
    ll cd = Mdiv(c, d);
    cout << ((ab + cd) % m + m) % m;
}