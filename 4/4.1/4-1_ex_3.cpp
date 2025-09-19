#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<int>> m_graph(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        m_graph[u][v] = 1;
        m_graph[v][u] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << m_graph[i][j];
        }
        cout << endl;
    }
}