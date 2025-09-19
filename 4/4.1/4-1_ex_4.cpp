#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    vector <vector <int>> m_graph(n, vector<int>(n, 0));
    for (int i = 1; i <= n; i++) {
        int d; cin >> d;
        for (int j = 0; j < d; j++) {
            int u = i, v; cin >> v; u--; v--;
            m_graph[u][v] = 1;
            m_graph[v][u] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << m_graph[i][j];
        }
        cout << endl;
    }
}