#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;
    map <int, set <int>> l_graph;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        l_graph[u].insert(v);
        l_graph[v].insert(u);
    }
    for (int i = 1; i <= n; i++) {
        cout << l_graph[i].size() << " ";
        for (auto a : l_graph[i]) cout << a << " ";
        cout << endl;
    }
}