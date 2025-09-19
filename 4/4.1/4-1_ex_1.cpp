#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    map <int, vector<int>> l_graph;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char tmp;
            cin >> tmp;
            if (!(48 - tmp)) continue;
            else l_graph[i].push_back(j + 1);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << l_graph[i].size() << " ";
        for (auto a : l_graph[i]) cout << a << " ";
        cout << endl;
    }
}