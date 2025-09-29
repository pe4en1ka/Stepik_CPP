//          For stepik
//          Made by coder228
#include <bits/stdc++.h>
using namespace std;

vector <unordered_set <int>> adj_l;
vector <int> ord, color;

bool dfs (int v) {
   color[v] = 1;
   for (auto u : adj_l[v]) {
      if (color[u] == 0) {
         if (dfs(u)) return true;
      }
      else if (color[u] == 1) {
         return true;
      }
   }
   color[v] = 2;
   ord.push_back(v);
   return false;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int n, m; cin >> n >> m;

   adj_l.assign(n + 1,unordered_set <int>());
   color.assign(n+1,0);

   for (int i = 1; i <= m; i++) {
      int u, v; cin >> u >> v;
      adj_l[u].insert(v);
   }
   for (int i = 1; i <= n; i++) {
      if (!color[i]) {
         if (dfs(i)) {cout << "IMPOSSIBLE"; return 0;}
      }
   }
   reverse(ord.begin(), ord.end());
   for (int i = 0; i < n - 1 ; i++) {
      if (adj_l[ord[i]].find(ord[i + 1]) == adj_l[i].end()) {cout << "NO"; return 0;}
   }
   cout << "YES";
}