//          For stepik
//          Made by coder228
#include <bits/stdc++.h>
using namespace std;

void comp_dfs(int v, vector <bool> &vis, vector <vector <int>> &al, int &vc, int &ec) {
    vis[v] = true;
    vc++;
    ec += static_cast<int>(al[v].size());
    for (auto u : al[v]) {
        if (vis[u]) continue;
        comp_dfs(u, vis, al, vc, ec);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;
    vector <vector <int>> adj_l(n + 1);
    for (int i = 1; i <= m; i ++) {
        int u,v; cin >> u >> v;
        adj_l[u].push_back(v);
        adj_l[v].push_back(u);
    }
    vector <bool> visited(n + 1);
    bool cycle_found = false;
    for (int i = 1; i <= n; i ++) {
        if (!visited[i]) {
            int vertex_cnt = 0, edge_cnt = 0;
            comp_dfs(i, visited, adj_l, vertex_cnt, edge_cnt);
            edge_cnt /= 2;

            if (edge_cnt >= vertex_cnt) { cycle_found = true; break;}
        }
    }

    cout << "NO";
}