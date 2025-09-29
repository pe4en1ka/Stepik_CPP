//          For stepik
//          Made by coder228
#include <bits/stdc++.h>
using namespace std;



bool is_TS(int n, vector <vector <int>> &al, vector <int> &ord, vector <int> &pos) {
    if (ord.size() != n + 1) return false;
    for (int i = 1; i <= n; i++) {
        int v = ord[i];
        if (v < 1 || v > n || pos[v] != -1) return false;
        pos[v] = i;
    }
    for ( int v = 1; v <= n; v++ ) {
        for (auto u : al[v]) {
            if (u == v) return false;
            if (pos[u] < pos[v]) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;
    vector <vector <int>> adj_l;
    vector <int> order, pos;
    adj_l.assign(n+1, vector<int>());
    order.assign(n+1, 0);
    pos.assign(n+1, -1);

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj_l[u].push_back(v);
    }
    for (int i = 1; i<= n; i++) {
        cin >> order[i];
    }
    cout << (is_TS(n, adj_l, order, pos) ? "YES" : "NO");
}