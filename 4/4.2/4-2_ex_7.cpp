//          For stepik
//          Made by coder228
#include <bits/stdc++.h>
using namespace std;

void cycle_dfs(int v, vector <vector <int>> &al, vector <int> &c, bool &cf) {
    c[v] = 'g';
    for (auto u : al[v]) {
        if (c[u] == 'g') {
            cf = true;
        }
        if (c[u] == 'w') {
            cycle_dfs(u, al, c, cf);
        }
    }
    c[v] = 'b';
}

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
    bool cycle_found = false;
}