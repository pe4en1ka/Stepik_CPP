#include <bits/stdc++.h>
using namespace std;
#define ll long long

constexpr int MAXN = 300050;
ll a[MAXN], partSum[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = a[0], sum = 0, min_sum = 0;
    for (int r=0; r < n; r++) {
        sum += a[r];
        ans = max (ans, sum - min_sum);
        min_sum = min (min_sum, sum);
    }
    cout << ans;
}