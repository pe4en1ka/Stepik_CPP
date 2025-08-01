#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(n, vector <int>(m));
    vector <vector <int>> dp(n, vector <int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    dp[0][0] = a[0][0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + a[i][0];
    }
    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j - 1] + a[0][j];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]}) + a[i][j];
        }
    }
    vector < pair <int, int >> r;
    int x = n - 1, y = m - 1;
    while (x >= 0 && y >= 0) {
        r.emplace_back(x, y);
        if (x - 1 >= 0 && y - 1 >= 0 && dp[x][y] == dp[x - 1][y - 1] + a[x][y]) {
            x--;
            y--;
        }
        else if (x - 1 >= 0 && dp[x][y] == dp[x - 1][y] + a[x][y]) {
            x--;
        }
        else {
            y--;
        }
    }
    cout << dp[n - 1][m - 1] << " " << r.size() << '\n';
    for (int i = static_cast <int>(r.size()) - 1; i >= 0; i--) {
        cout << r[i].first + 1 << " " << r[i].second + 1 << '\n';
    }
}