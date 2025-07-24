#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(n, vector<int>(m, 0));
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i][0] = abs(a[i][0] - a[i - 1][0]) + dp[i - 1][0];
    }
    for (int j = 1; j < m; j++) {
        dp[0][j] = abs(a[0][j] - a[0][j - 1]) + dp[0][j - 1];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = min(abs(a[i][j] - a[i - 1][j]) + dp[i - 1][j], abs(a[i][j] - a[i][j - 1]) + dp[i][j - 1]);
        }
    }
    cout << dp[n - 1][m - 1] << endl;
}