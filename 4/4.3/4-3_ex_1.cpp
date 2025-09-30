//          For stepik
//          Made by coder228
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;
    vector <vector <int>> adj_l(n + 1);
    queue <int> q;
    vector <int> waves;
    vector <bool> used (n + 1, false);
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj_l[u].push_back(v);
        adj_l[v].push_back(u);
    }
    int s; cin >> s;
    q.push(s);
    used[s] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : adj_l[v]) {
            if (used[u]) continue;
            used[u] = true;
            q.push(u);
            waves.push_back(u);
        }
    }
}