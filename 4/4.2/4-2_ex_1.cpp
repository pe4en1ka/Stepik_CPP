#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
void dfs(int v, vector<bool> &us, map<int, set<int>> &lg) {
    us[v - 1] = true;
    cout << v << " ";
    cnt++;
    for (auto u : lg[v]) {
        if (us[u - 1]) {
            continue;
        }
        dfs(u, us, lg );
        cout << v << " ";
    }
}

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
    int start; cin >> start;
    vector <bool> used(n, false);
    dfs(start, used, l_graph);
}