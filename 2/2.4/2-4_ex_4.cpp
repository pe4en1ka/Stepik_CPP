#include <bits/stdc++.h>
using namespace std;
#define ll long long

constexpr ll mod = 1e9 + 7;

ll f(ll n) {
    ll res = 1;
    for (ll i = 2; i <= n; i++) {
        res = (res * i) % mod;
    }
    return (res);
}

ll Mfastpow(ll a, ll n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 1) {
        return ((a * Mfastpow(a, n - 1)) % mod + mod) % mod;
    }
    ll tmp = Mfastpow(a, n / 2);
    return ((tmp * tmp) % mod + mod) % mod;
}

ll Mmult(ll a, ll b) {
    return ((a * b) % mod + mod) % mod;
}

ll Mdiv (ll a, ll b) {
    return Mmult(a,Mfastpow(b, mod - 2));
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
        ll fac_n = f(n);
        for (ll k = 1; k <= l && m * k <= n; k++) {
            ll fac_mk = f(m * k);
            ll fac_nmk = f(n - m * k);
            sum = (sum + Mdiv(fac_n, Mmult(fac_mk, fac_nmk))) % mod;


        }
        cout << sum % mod;
        return 0;
    }
}