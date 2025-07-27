#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector <vector <bool>> a(n, vector <bool> (m, false));
    vector <vector <int>> dp(n, vector <int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            if (tmp) {
                a[i][j] = true;
            }
        }
    }
    dp[0][0] = 1;
    int ii = 1;
    while (ii < n && !a[ii][0]) {
        dp[ii][0] = 1;
        ii++;
    }
    int jj = 1;
    while (jj < m && !a[0][jj]) {
        dp[0][jj] = 1;
        jj++;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = ((dp[i-1][j] % MOD + dp[i - 1][j - 1] % MOD) % MOD + dp[i][j - 1] % MOD) % MOD;
            if (a[i][j]) {
                dp[i][j] = 0;
            }
        }

    }
    cout << dp[n-1][m-1] << endl;
}