//          For stepik
//          Made by coder228
#include <bits/stdc++.h>
using namespace std;

bool cycle_dfs(int v, vector <vector <int>> &al, vector <char> &c, vector <int> &pa, vector <int> & cy) {
    c[v] = 'g';
    for (auto u : al[v]) {
        if (c[u] == 'g') {
            pa[u] = v;
            if (cycle_dfs(u, al, c, pa, cy)) {
                return true;
            }
        }
        else if (c[u] == 'g') {
            cy.push_back(u);
            for (int i = v; i != u; i = pa[i]) {
                cy.push_back(i);
            }
            cy.push_back(u);
            reverse(cy.begin(), cy.end());
            return true;
        }
    }
    c[v] = 'b';
    return false;
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
    vector <int> parent(n + 1);
    vector <int> cycle(n + 1);

    for (int i = 1; i <= n; i++) {
        if (color[i]) {
            if (cycle_dfs(i, adj_l, color, parent, cycle)) {
                break;
            }
        }
    }
    if (cycle.empty()) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        cout << cycle.size() << endl;
        for (auto a : cycle) {
            cout << a << " ";
        }
    }
}