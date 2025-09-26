//          For stepik
//          Made by coder228
#include <bits/stdc++.h>
using namespace std;

bool dfs(const int v, const int a, vector <vector <int>> const &al, vector <bool> &vis, vector <int> &cy, vector <int> &pa) {
    vis[v] = true;
    for (auto u : al[v]) {
        if (u == a) {
            continue;
        }
        if (!vis[u]){
            pa[u] = v;
            if (dfs(u, v, al, vis, cy, pa)) {
                return true;
            }
        }
        else {
            cy.push_back(u);
            for (int cur = v; cur != u; cur = pa[cur]) {
                cy.push_back(cur);
            }
            return true;
        }
    }
    return false;
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

    vector <int> parent(n + 1),  cycle;
    vector <bool> visited(n + 1);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj_l, visited, cycle, parent)) break;
        }
    }
    if (cycle.empty()) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        cout << cycle.size() << endl;
        for (auto x : cycle) cout << x << " ";
    }
}