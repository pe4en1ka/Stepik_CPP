#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(n, vector <int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector <vector <pair<pair<int, int>, ll>>> dp(n + 2, vector <pair<pair<int, int>, ll>>(m + 2, {{0,0}, 1000000100}));
    dp[2][2] = {{1,1}, a[2][2]};
    for ( int k = 0; k < n + m + 1; k++) {
        int s = max(0, k - m + 1);
        int e = min(k, n - 1);
        for (int i = s; i <= e; i++) {
            int j = k - i;
            dp[i][j] = min({dp[i + 2][j + 1].second, dp[i + 2][j - 1]. second, dp[i - 1][j + 2].second, dp})
        }
    }
}