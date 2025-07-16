#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll extgsd(ll a, ll b, ll & x, ll & y ) {
    if ( a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    else {
        ll x1, y1;
        ll d = extgsd( b % a, a, x1, y1 );
        x = y1 - ( b / a ) * x1;
        y = x1;
        return d;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll a, n ,m;
    cin >> a >> n >> m;
    ll x, y, rev;
    ll gsd = extgsd(a, m, x, y);
    if (gsd != 1) {
        cout << -1;
        return 0;
    }
    else {
        rev = (x % m + m) % m;
    }
}