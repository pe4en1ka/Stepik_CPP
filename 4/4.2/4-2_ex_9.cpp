#include <bits/stdc++.h>
using namespace std;

vector <vector<int>> adj_l;
vector<int> color, order;

bool dfs(int v){
  color[v] = 1;
  for(auto u : adj_l[v]) {
    if(color[u] == 0) {
      if (dfs(u)) {
        return true;
      }
    }
    else if(color[u] == 1){
      return true;
    }
  }
  color[v] = 2;
  order.push_back(v);
  return false;
}

int main() {
  int n, m; cin >> n >> m;
  adj_l.assign(n+1, vector<int>());
  color.assign(n+1, 0);

  for (int i = 1;i<=m;i++){
    int u, v; cin>>u>>v;
    adj_l[u].push_back(v);
  }
  bool cycle = false;
  for (int i = 1;i<=n;i++){
    if(color[i] == 0) {
      if(dfs(i)) {cycle = true; break;}
    }
  }
  if (cycle) {cout << "NO"; return 0;}
  else{
    reverse(order.begin(), order.end());
    cout << "YES" << endl;
    for (auto v : order) cout << v << " ";
  }
}