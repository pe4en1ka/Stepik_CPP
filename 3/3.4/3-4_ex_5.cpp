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
    vector <vector<pair<ll, pair<int, int>>>> dp(n, vector<pair<ll, pair<int, int>>>(m));
    vector <pair<ll, int>> le(n - 1);
    vector <pair<ll, int>> up(m - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    dp[0][0] = {a[0][0], {-1, -1}};
    ll min_le = dp[0][0].first;
    ll min_up = min_le;
    pair <int, int> best_move = {0, 0};
    for (int i = 1; i < n; i++) {
        dp[i][0].first = min_up + a[i][0];
        dp[i][0].second = best_move;
        if (min_up > dp[i][0].first) {
            min_up = dp[i][0].first;
            best_move = {i, 0};
        }
    }
    best_move = {0, 0};
    for (int j = 1; j < m; j++) {
        dp[0][j].first = min_le + a[0][j];
        dp[0][j].second = best_move;
        if (min_le > dp[0][j].first) {
            min_le = dp[0][j].first;
            best_move = {0, j};
        }
    }
    for (int i = 0; i < n - 1; i++) {
        le[i].first = dp[i + 1][0].first;
        le[i].second = 0;
    }
    for (int j = 0; j < m - 1; j++) {
        up[j].first = dp[0][j + 1].first;
        up[j].second = 0;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            min_le = le[i - 1].first;
            min_up = up[j - 1].first;
            if (min_le > min_up) {
                best_move = {up[j - 1].second, j};
            }
            else {
                best_move = {i, le[i - 1].second};
            }
            dp[i][j].first = min(min_le,min_up) + a[i][j];
            dp[i][j].second = best_move;
            if (min_le > dp[i][j].first) {
                le[i - 1].first = dp[i][j].first;
                le[i - 1].second = j;
            }
            if (min_up > dp[i][j].first) {
                up[j - 1].first = dp[i][j].first;
                up[j - 1].second = i;
            }
        }
    }
    for (const auto& i : dp) {
        for (auto j : i) {
            cout << j.first << ", " << j.second.first + 1 << " " << j.second.second + 1<< "\t";
        }
        cout << endl;
    }
     
}