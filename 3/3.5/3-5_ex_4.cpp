#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int s, n;
    cin >> s >> n;
    vector <int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    vector <vector <bool>> dp(n + 1, vector <bool>(s + 1,false));
    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {
        int cur_w = w[i - 1];
        for (int j = 0; j <= s; j++) {
            if (dp[i-1][j]) {
                dp[i][j] = true;
            }
            else if (j >= cur_w && dp[i-1][j - cur_w]) {
                dp[i][j] = true;
            }
        }
    }
    
}