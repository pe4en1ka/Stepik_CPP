#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int s, n;
    cin >> s >> n;
    vector<int> weight(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    vector<int> cost(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> cost[i];
    }

    vector <vector <int>> dp(n + 1, vector <int> (s + 1, 0));
    vector <int> path;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= s; j++) {
            if (weight[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + cost[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int max_cost = 0;
    int best_j = 0;
    for (int j = 0; j <= s; j++) {
        if (dp[n][j] > max_cost) {
            max_cost = dp[n][j];
            best_j = j;
        }
    }
    int i = n;
    int j = best_j;
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            path.push_back(i);
            j -= weight[i - 1];
        }
        i--;
    }
    cout << dp[n][s] << " " << path.size() << endl;
    for (int q = static_cast<int>(path.size()) - 1; q >= 0; q--) {
        cout << path[q] << " ";
    }
}