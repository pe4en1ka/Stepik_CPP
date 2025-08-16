#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector <vector<int>> a(n, vector<int>(m));
    vector <vector<ll>> dp(n, vector<ll>(m));
    vector <ll> le(m - 1);
    vector <ll> up(n - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    dp[0][0] = a[0][0];
    pair <ll, int> min_le = {dp[0][0], 0};
    pair <ll, int> min_up = min_le;
    for (int i = 1; i < n; i++) {
        dp[i][0] = min_up.first + a[i][0];
        if (min_up.first > dp[i][0]) {
            min_up.first = dp[i][0];
        }
    }
    for (int j = 1; j < m; j++) {
        dp[0][j] = min_le.first + a[0][j];
        if (min_le.first > dp[0][j]) {
            min_le.first = dp[0][j];
        }
    }
    for (int i = 0; i < n - 1; i++) {
        le[i] = dp[i + 1][0];
    }
    for (int j = 0; j < m - 1; j++) {
        up[j] = dp[0][j + 1];
    }
    min_le = {le[0], 1};
    min_up = {up[0], 1};
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = min(min_le.first,min_up.first) + a[i][j];
            if (min_le.first > dp[i][j]) {
                min_le.first = dp[i][j];
                min_le.second = j;
            }
            if (min_up.first > dp[i][j]) {
                min_up.first = dp[i][j];
            }
        }
    }
    for (const auto& i : dp) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}