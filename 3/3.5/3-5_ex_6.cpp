#include <bits/stdc++.h>
using namespace std;
constexpr int INF = LLONG_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int s, n;
    cin >> s >> n;
    vector <int> w(n);
    vector <int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector <vector<int>> dp(n + 1, vector<int>(s + 1,-INF ));
    dp[0][0] = 0;

     for (int i = 1; i <= n; i++) {
         for (int j = 0; j <= s; j++) {
             dp[i][j] = (j >= w[i]) ? max(dp[i - 1][j],dp[i - 1][j - w[i]] + c[i]) : dp[i - 1][j];
         }
     }
    int ans = 0;
    for (int j = 0; j <= s; j++) {
        ans = max(ans, dp[n][j]);
    }
    cout << ans << endl;
}