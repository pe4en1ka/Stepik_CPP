//          For stepik
//          Made by coder228
#include <bits/stdc++.h>
using namespace std;

void dfs_timer(int v, int a, vector <vector <int>> &cl, vector<int> &in, vector <int> &out, int& t) {
    in[v] = t++;
    for (int u : cl[v]) {
        if (u == a) continue;
        dfs_timer(u, v, cl, in, out, t);
    }
    out[v] = t++;
}

bool is_anc(int v ,int u, vector <int> const &in, vector <int> const &out) {
    return in[v] <= in[u] &&out[v] >= out[u];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;
    vector <pair<int, int>> edges(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }
    int q; cin >> q;
    vector<int> cand(q + 1);
    set <int> cand_set;
    for (int i = 1; i <= q; i++) {
        cin >> cand[i];
        cand_set.insert(cand[i]);
    }
    if (q != n - 1) {cout << "NO\n"; return 0;}

    vector <vector <int>> tree_adj(n + 1);
    for (int i : cand) {
        int u = edges[i].first, v = edges[i].second;
        tree_adj[u].push_back(v);
        tree_adj[v].push_back(u);
    }
    vector <bool> visited(n + 1);
    stack <int> st;
    st.push(1);
    visited[1] = true;
    int cnt = 1;
    while (!st.empty()) {
        int v = st.top();
        st.pop();
        for (int u : tree_adj[v]) {
            if (!visited[u]) { visited[u] = true; cnt++; st.push(u);}
        }
    }
    if (cnt != n) {cout << "NO\n"; return 0;}

    vector <pair<int, int>> non_tree;
    for (int i = 1; i <= m; i++) {
        if (cand_set.find(i) == cand_set.end()) non_tree.emplace_back(edges[i]);
    }
    if (non_tree.empty()) {cout << "YES\n"; return 0;}

    for (int r = 1; r <= n; r++) {
        vector <int> tin(n + 1), tout(n + 1);
        int t = 0;
        dfs_timer(r, -1, tree_adj, tin, tout, t);
        bool valid = true;
        for (auto e : non_tree) {
            int u = e.first, v = e.second;
            if (!is_anc(u, v, tin, tout) && !is_anc(v, u, tin, tout)) { valid = false; break; }
        }
        if (valid) {cout << "YES\n"; return 0;}
    }
    cout << "NO\n";
}