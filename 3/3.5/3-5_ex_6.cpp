#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int S, n;
    cin >> S >> n;
    vector<int> weights(n);
    vector<int> costs(n);

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(S + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= S; j++) {
            if (weights[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + costs[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][S] << endl;

    return 0;
}