#include <bits/stdc++.h>
using namespace std;
#define ll long long

constexpr int m = 1e6 + 7;
ll a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b;
    a *= a;
    b *= b;
    cout << (((a % m - b % m) % m) + m) % m;
}