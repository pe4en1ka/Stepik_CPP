#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector <ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector <ll> dp(n, 0);
    deque <ll> q;
    vector <ll> prev(n);
    dp[0] = a[0];
    q.push_back(-1);
    q.push_back(0);
    prev[0] = -1;
    for (int i = 1; i < n; i++) {
        if (i < k) {
            prev[i] = (0 > dp[q.back()]) ? q.back() : -1;
            dp[i] = (prev[i] == -1) ? a[i] : a[i] + dp[q.back()];
            ll j = (dp[q.back()] < dp[i]) ? q.back() : i;
            q.pop_back();
            q.push_back(j);
        }
        else {
            while (!q.empty() && q.front() < i - k) {
                q.pop_front();
            }
            dp[i] = a[i] + dp[q.front()];
            prev[i] = q.front();
            while (!q.empty() && dp[q.back()] >= dp[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
    }

    vector <ll> path;
    ll x = n - 1;
    while (x != -1) {
        path.push_back(x);
        x = prev[x];
    }

    cout << dp[n - 1] << " " << path.size() << endl;
    for (int i = static_cast<int>(path.size()) - 1; i >= 0; i--) {
        cout << path[i] + 1 << " ";
    }
    cout << endl;
}