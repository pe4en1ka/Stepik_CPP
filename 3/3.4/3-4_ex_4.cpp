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
    vector <vector <pair<pair<int, int>, ll>>> dp(n, vector <pair<pair<int, int>, ll>>(m, {{0,0}, LLONG_MAX}));
    dp[0][0].second = a[0][0];
    dp[0][0].first = {-1, -1};
    for ( int k = 0; k < n + m + 1; k++) {
        int s = max(0, k - m + 1);
        int e = min(k, n - 1);
        for (int i = s; i <= e; i++) {
            int j = k - i;
            ll minn = LLONG_MAX;
            pair<int,int> best_move = {-1, -1};
            if (i >= 2 && j + 1 < m) {
                if (dp[i - 2][j + 1].second < minn) {
                    minn = dp[i - 2][j + 1].second;
                    best_move = {i - 2, j + 1};
                }
            }
            if (i >= 2 && j - 1 >= 0) {
                if (dp[i - 2][j - 1].second < minn) {
                    minn = dp[i - 2][j - 1].second;
                    best_move = {i - 2, j - 1};
                }
            }
            if (i - 1 >= 0 && j - 2 >= 0) {
                if (dp[i - 1][j - 2].second < minn) {
                    minn = dp[i - 1][j - 2].second;
                    best_move = {i - 1, j - 2};
                }
            }
            if (i + 1 < n && j - 2 >= 0) {
                if (dp[i + 1][j - 2].second < minn) {
                    minn = dp[i + 1][j - 2].second;
                    best_move = {i + 1, j - 2};
                }
            }
            if (minn != LLONG_MAX) {
                dp[i][j].second = minn + a[i][j];
                dp[i][j].first = best_move;
            }
        }
    }
    if (dp[n - 1][m - 1].second == LLONG_MAX) {
        cout << "NO" << '\n';
    }
    else {
        cout << "YES" << '\n';
        vector <pair<int, int>> r;
        int x = n - 1;
        int y = m - 1;
        while (x != -1 || y != -1) {
            r.emplace_back(x, y);
            int old_x = x, old_y = y;
            x = dp[old_x][old_y].first.first;
            y = dp[old_x][old_y].first.second;
        }
        cout << dp[n - 1][m - 1].second << " " << r.size() << '\n';
        for (int i = static_cast<int>(r.size() - 1); i >= 0; i--) {
            cout << r[i].first + 1 << " " << r[i].second + 1 << '\n';
        }
    }

}