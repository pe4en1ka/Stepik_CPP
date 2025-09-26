//          For stepik
//          Made by coder228
#include <bits/stdc++.h>
using namespace std;

void dfs(const int v, const int a, vector <vector <int>> const &al, vector <int> &vis) {
    vis[v] = true;
    for (auto u : al[v]) {
        if (u == a) continue;
        dfs(u, v, al, vis);
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;
    vector <vector <int>> adj_l(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj_l[u].push_back(v);
        adj_l[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj_l[i].begin(), adj_l[i].end());
    }

    vector <int> tin(n + 1), tout(n + 1), cycle;
    vector <bool> visited(n + 1);
    int timer = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs()
        }
    }
}