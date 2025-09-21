#include <bits/stdc++.h>
using namespace std;

bool comp_for_vertexes(pair<int, int> const &a, pair<int, int> const &b) {
    return a.first < b.first;
}

void dfs(int v, vector <vector <pair<int, int>>> const &lg, vector <bool> &vis, vector <int> &tt) {
    vis[v] = true;
    for (auto p : lg[v]) {
        int u = p.first, i = p.second;
        if (vis[u]) {
            continue;
        }
        tt.push_back(i);
        dfs(u, lg, vis, tt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;
    vector <vector <pair<int, int>>> l_graph(n + 1);
    vector <bool> visited(n + 1, false);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        l_graph[x].emplace_back(y, i + 1);
        l_graph[y].emplace_back(x, i + 1);
    }
    for (int i = 1; i <= n; i++) {
        sort(l_graph[i].begin(), l_graph[i].end(), comp_for_vertexes);
    }
    vector <int> tree_traversal;
    dfs(1, l_graph, visited, tree_traversal);
    cout << n - 1 << endl;
    for (auto i : tree_traversal) {
        cout << i << " ";
    }
}