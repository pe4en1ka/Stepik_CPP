//          For stepik
//          Made by coder228
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;

    vector <vector <int>> adj_l(n + 1);
    for (int i = 1; i <= n; i++) {
        int u, v; cin >> u >> v;
        adj_l[u].push_back(v);
    }
    vector <char> color(n + 1, 'w');
}