#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

constexpr int MAXN = 300500;
ull a[MAXN], partSum[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    a[0] = 0ULL;
    for (int i = 1; i < n + 1; i++) {
        cin >> a[i];
        partSum[i] = partSum[i - 1] + a[i];
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << partSum[r] - partSum[l - 1] << '\n';
    }
}