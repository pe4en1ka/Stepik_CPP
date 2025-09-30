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
    vector <int> dist(n + 1, 0);
    queue <int> q;
    vector <iboolt> visited(n + 1, 0);

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj_l[u].push_back(v);
        adj_l[v].push_back(u);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int s = i;
        dist[s] = 0;
        q.push(s);
        visited[s] = true;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto u : adj_l[v]) {

            }
        }
    }
}