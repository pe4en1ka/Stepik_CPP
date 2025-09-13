#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string j, s;
  cin >> j >> s;
  set<char> sett;
  for(int i = 0; i < j.length(); i++) {
    sett.insert(j[i]);
  }
  int cnt = 0;
  for (char a : sett) {
    for (int q = 0; q < s.length(); q++) {
      if (a == s[q]) {
        cnt++;
      }
    }
  }
  cout << cnt;
}