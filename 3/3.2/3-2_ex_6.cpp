#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

constexpr int MAXN = 100;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n; ull dp[MAXN] {0};
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n + 1; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n + 1];
}