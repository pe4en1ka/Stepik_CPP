#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll INF = LLONG_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector <ll> a(n + k);
    for (int i = k; i < n + k; i++) cin >> a[i];
    vector <pair <ll, int>> dp(n, {INF,-1});
    pair <ll,int>  min_win = {0, -1};
    for (int i = 0; i < k; i++) {
        dp[i].first = min_win.first + a[i + k];
        dp[i].second = min_win.second;

        if (dp[i].first < min_win.first) {
            min_win = {dp[i].first, i};
        }
    }
    min_win = {dp[0].first, 0};
    for (int i = 1; i < k; i++) {
        if (dp[i].first < min_win.first) {
            min_win = {dp[i].first, i};
        }
    }
}