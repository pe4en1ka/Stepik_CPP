#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector <int> a(n + 5, -1e9 - 100);
    vector <ll> dp(n + 5, -1e9 - 100);
    for (int i = 5; i < n + 5; i++) {
        cin >> a[i];
    }
    dp[4] = 0;
    dp[5] = a[5];
    for (int i = 6; i < n + 5; i++) {
        dp[i] = max({dp[i - 1], dp[i - 3], dp[i - 5]}) + a[i];
    }
    vector <int> r;
    int x = n + 4;
    while (x >= 5) {
        r.push_back(x);
        if (dp[x] == dp[x - 1] + a[x]) {
            x--;
        }
        else if (dp[x] == dp[x - 3] + a[x]) {
            x -= 3;
        }
        else {
            x -= 5;
        }
    }
    cout << dp[n + 4] << " " << r.size() << '\n';
    for (int i = static_cast<int>(r.size() - 1); i >= 0; i--) {
        cout << r[i] - 4 << " ";
    }
}