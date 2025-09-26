//          For stepik
//          Made by coder228
#include <bits/stdc++.h>
using namespace std;

bool dfs(int v, vector <vector <int>> &al, vector <int> &c, vector <int> &pa, vector <int> &cy) {
    c[v] = 1;
    for (auto u : al[v]) {
        if (c[u] == 0) {
            pa[u] = v;
            if (dfs(u, al, c, pa, cy)) return true;
        }
        else if (c[u] == 1) {
            cy.push_back(v);
        }
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
    }

    vector <int> color(n + 1), parent(n + 1), cycle;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            if (dfs(i, adj_l, color, parent, cycle)) {
                break;
            }
        }
    }
}