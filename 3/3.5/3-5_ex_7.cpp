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

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= s; j++) {

        }
    }
}