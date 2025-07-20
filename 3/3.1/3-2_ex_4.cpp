#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 500500;
bool a[MAXN];
int dp[MAXN];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    string arr;
    cin >> arr;
    for (int i = 1; i <= n; i++) {
        char c = arr[i - 1];
        if (c == '0') {
            a[i] = false;
        }
        else {
            a[i] = true;
        }
    }
    if (a[n]) {cout << 0; return 0;}
    dp[0] = 1;
    dp[1] = 1 - a[1];
    dp[2] = dp[0] + dp[1];
    if (a[2]) {
        dp[2] = 0;
    }
    for (int i = 3; i <= n; i++) {
    dp[i] = (dp[i - 1] % MOD + dp[i - 2] % MOD + dp[i - 3] % MOD) % MOD;
        if (a[i]) {
            dp[i] = 0;
        }
    }
    cout << dp[n];
}