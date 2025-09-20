#include <bits/stdc++.h>
using namespace std;

bool comp_for_pairs(pair<int,int> const &a, pair<int,int> const &b) {
    if (a.first < b.first) return true;
    else if (a.first == b.first) if  (a.second < b.second) return true; else return false;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    vector <pair <int, int>> l_ribs;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char tmp; cin >> tmp;
            if (tmp == '1' && i < j) l_ribs.emplace_back(i, j);
        }
    }
    sort(l_ribs.begin(), l_ribs.end(), comp_for_pairs);
    cout << l_ribs.size() << endl;
    for (auto a : l_ribs) {
        cout << a.first << " " << a.second << endl;
    }
}