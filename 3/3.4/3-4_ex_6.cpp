#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll INF = LLONG_MAX;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector <vector <ll>> a(n, vector<ll>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  vector <vector <pair <ll, pair<int, int>>>> dp(n, vector<pair<ll, pair<int, int>>>(m, {INF,{-1, -1}}));
  vector <pair<ll, pair<int, int>>> le(n, {INF,{-1, -1}});
  vector <pair<ll, pair<int, int>>> up(m, {INF,{-1, -1}});
  int di_s = n + m - 1;
  vector <pair<ll, pair<int, int>>> di(di_s, {INF,{-1, -1}});

  dp[0][0] = {a[0][0], {-1, -1}};
  le[0] = {a[0][0], {0, 0}};
  up[0] = {a[0][0], {0, 0}};
  int d = 0;
  int idx = d + (m - 1);
  di[idx] = {a[0][0], {0, 0}};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 && j == 0) {
        continue;
      }
      ll cost = a[i][j];
      d = i - j;
      idx = d + (m - 1);

      if (le[i].first != INF) {
        ll candidate = le[i].first + cost;
        if (candidate < dp[i][j].first) {
          dp[i][j].first = candidate;
          dp[i][j].second = le[i].second;
        }
      }
      if (up[j].first != INF) {
        ll candidate = up[j].first + cost;
        if (candidate < dp[i][j].first) {
          dp[i][j].first = candidate;
          dp[i][j].second = up[j].second;
        }
      }
      if (di[idx].first != INF) {
        ll candidate = di[idx].first + cost;
        if (candidate < dp[i][j].first) {
          dp[i][j].first = candidate;
          dp[i][j].second = di[idx].second;
        }
      }

      if (dp[i][j].first < le[i].first) {
        le[i] = {dp[i][j].first, {i, j}};
      }
      if (dp[i][j].first < up[j].first) {
        up[j] = {dp[i][j].first, {i, j}};
      }
      if (dp[i][j].first < di[idx].first) {
        di[idx] = {dp[i][j].first, {i, j}};
      }
    }
  }
  vector <pair <ll, ll>> path;
  int x = n - 1;
  int y = m - 1;
  while (x != -1 && y != -1) {
    path.emplace_back(x, y);
    pair<int, int> prev = dp[x][y].second;
    x = prev.first;
    y = prev.second;
  }
  reverse(path.begin(), path.end());

  cout << dp[n-1][m-1].first << " " << path.size() << "\n";
  for (auto q : path) {
    cout << q.first + 1 << " " << q.second + 1 << "\n";
  }
}