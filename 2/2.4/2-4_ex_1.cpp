#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

ull n, m;

ull Mfastpow(ull a,ull n, ull m) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 1) {
        return (a * Mfastpow(a, n - 1, m)) % m;
    }
    ull tmp = Mfastpow(a, n / 2, m);
    return (tmp * tmp) % m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    cout << Mfastpow(n, n, m);
}