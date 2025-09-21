#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector <vector <int>> const &lg, vector <pair<int, int>> const &ed, vector <bool> &vis, int anc, vector <int> &tt) {
    vis[v - 1] = true;
    for (int i = 1; i < ed.size(); i++) {
        int x = v, y = anc;
        if (ed[i].first == x && ed[i].second == y || ed[i].first == y && ed[i].second == x) {
            tt.push_back(i);
            break;
        }
    }
    for (auto u : lg[v]) {
        if (vis[u - 1]) {
            continue;
        }
        dfs(u, lg, ed, vis, v, tt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;
    vector <vector <int>> l_graph(n + 1);
    vector <pair<int, int>> edges(m + 1);
    vector <bool> visited(n);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        l_graph[x].push_back(y);
        l_graph[y].push_back(x);
        edges[i + 1] = {x, y};
    }
    for (int i = 1; i <= n; i++) {
        sort(l_graph[i].begin(), l_graph[i].end());
    }
    vector <int> tree_traversal;
    dfs(1, l_graph, edges, visited, -1, tree_traversal);
    cout << n - 1 << endl;
    for (auto i : tree_traversal) {
        cout << i << " ";
    }
}