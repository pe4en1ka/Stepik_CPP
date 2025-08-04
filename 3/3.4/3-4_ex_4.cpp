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
    vector <vector <pair<pair<int, int>, ll>>> dp(n + 4, vector <pair<pair<int, int>, ll>>(m + 4, {{0,0}, 1000000100}));
    dp[2][2] = {{1,1}, a[0][0]};
    for ( int k = 2; k < n + m + 5; k++) {
        int s = max(2, k - m - 1);
        int e = min(k, n + 1);
        for (int i = s; i <= e; i++) {
            int j = k - i + 2;
            dp[i][j].second = min({dp[i - 2][j + 1].second, dp[i - 2][j - 1]. second, dp[i - 1][j - 2].second, dp[i + 1][j - 2].second}) + a[i - 2][j - 2];
            if (dp[i][j].second == dp[i - 2][j + 1].second + a[i - 2][j - 2]) {
                dp[i][j].first.first = i - 2 - 2;
                dp[i][j].first.second = j + 1 - 2;
            }
            else if (dp[i][j].second == dp[i - 2][j - 1].second + a[i - 2][j - 2]) {
                dp[i][j].first.first = i - 2 - 2;
                dp[i][j].first.second = j - 1 - 2;
            }
            else if (dp[i][j].second == dp[i - 1][j - 2].second + a[i - 2][j - 2]) {
                dp[i][j].first.first = i - 1 - 2;
                dp[i][j].first.second = j - 2 - 2;
            }
            else {
                dp[i][j].first.first = i + 1 - 2;
                dp[i][j].first.second = j - 2 - 2;
            }
        }
    }
    if (dp[n + 1][m + 1].second >= 1000000000) {
        cout << "NO" << '\n';
        return 0;
    }
    else {
        cout << "YES" << '\n';
        vector <pair<int, int>> r;
        int x = n + 1;
        int y = m + 1;
        while (x != 1 && y != 1) {
            r.emplace_back(x, y);
            int old_x = x, old_y = y;
            x = dp[old_x][old_y].first.first;
            y = dp[old_x][old_y].first.second;
        }
        cout << dp[n + 1][y + 1].second << " " << r.size() - 1 << '\n';
        for (int i = static_cast<int>(r.size() - 1); i >= 0; i--) {
            cout << r[i].first << " " << r[i].second << '\n';
        }
    }

}