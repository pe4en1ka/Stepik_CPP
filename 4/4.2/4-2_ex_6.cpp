//          For stepik
//          Made by coder228
#include <bits/stdc++.h>
using namespace std;

void comp_dfs(int v, vector <bool> &vis, vector <vector <int>> &al, int &cnt, set <int> &p) {
    vis[v] = true;
    p.insert(v);
    cnt++;
    for (auto u : al[v]) {
        if (vis[u]) continue;
        comp_dfs(u, vis, al, cnt, p);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;
    vector <vector <pair<int, vector <int>>>> adj_l(n + 1);
    for (int i = 1; i <= m; i ++) {
        int u,v; cin >> u >> v;
        adj_l[u].push_back(v).second.push_back(i);
        adj_l[v].push_back(u);
    }
    vector <bool> visited(n + 1);
    vector <int> v_comp(n + 1);
    set <int> path;
    int vert = 0, st = 0, con_com = 0;
    while (vert != n) {
        for (int i = 1; i <= n; i ++) {
            if (!visited[i]) {st = i; break;}
        }
        comp_dfs(st, visited, adj_l, vert, path);
        con_com++;
        for (auto u: path) {
            v_comp[u] = con_com;
        }
        path.clear();
    }


}