#include <bits/stdc++.h>
using namespace std;
#define ll long long

constexpr int MAXN = 1050;
int a[MAXN];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    int ans = -1;
    for (int i = 1; i <= m; i++) {
        int x = i;
        ll mem = a[0];
        for (int j = 1; j <= n; j++) {
            mem = (mem*x % m + a[j] % m) % m;
        }
        if (mem == 0) {
            ans = x;
            break;
        }
    }
    cout << ans;
}