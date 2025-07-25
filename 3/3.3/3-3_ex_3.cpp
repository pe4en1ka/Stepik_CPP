#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
         for (int k = 0; k <= i; k++) {
            cin >> a[i][k];
        }
    }
    if (n == 1) {
        cout << a[0][0] << endl;
        return 0;
    }
    dp[0][0] = a[0][0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + a[i][0];
        dp[i][i] = dp[i - 1][i - 1] + a[i][i];
    }                                           // База
    for (int i = 2; i < n; i++) {
        for (int k = 1; k <= i; k++) {
            dp[i][k] = max(dp[i - 1][k], dp[i - 1][k - 1]) + a[i][k];
        }
    }
    int ans = -1e9;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[n - 1][i]);
    }
    cout << ans << endl;
}