#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int s, n;
    cin >> s >> n;

    vector <int> w(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    vector <vector<int>> dp(n+1, vector<int>(s + 1,0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i][j] = (w[i] <= j) ? dp[i - 1][j] || dp[i - 1][j - w[i]] : dp[i - 1][j];
        }
    }
    for (int we = s; we >= 0; we--) {
        if (dp[n][we] == 1) {
            cout << we << " ";
            return 0;
        }
    }
}