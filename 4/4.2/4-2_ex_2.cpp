#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector <bool> &us, map <int, set<int>> &lg, int &cnt, set <int> &path) {
    us[v - 1] = true;
    path.insert(v);
    cnt++;
    for (auto u : lg[v]) {
        if (us[u - 1]) {
            continue;
        }
        dfs(u, us, lg, cnt, path);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;
    map <int, set<int>> l_graph;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        l_graph[u].insert(v);
        l_graph[v].insert(u);
    }
    vector <bool> used(n, false);
    vector <int> top(n, 0);
    set <int> path;
    int peaks = 0; int st = 0; int con_comp = 0;
    while (peaks != n) {
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                st = i + 1;
                break;
            }
        }
        dfs(st, used, l_graph, peaks, path);
        con_comp++;
        for (auto i : path) {
            top[i - 1] = con_comp;
        }
        path.clear();
    }
    cout << con_comp << endl;
    for (auto i: top) {
        cout << i << " ";
    }
}