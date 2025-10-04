//          For stepik
//          Made by coder228
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;
    vector <vector <int>> dist(n + 1, vector <int>(m + 1, -1));
    int p, q; cin >> p >> q;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    vector <pair<int, int>> step = {
        {p,q}, {p, -q}, {-p, q}, {-p, -q},
        {q, p}, {q, -p}, {-q, p}, {-q, -p}
    };
    queue <pair<int, int>> qv;
    auto check = [&](int x, int y) {return 1 <= x && x <= n && 1 <= y && y <= m; };

    dist[x1][y1] = 0;
    qv.push({x1, y1});
    while (!qv.empty()) {
        pair <int, int> cord = qv.front();
        int x = cord.first, y = cord.second;
        qv.pop();
        for (auto ch : step) {
            int nx = ch.first + x, ny = ch.second + y;
            if (!check(nx, ny) || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            qv.push({nx, ny});
        }
    }
    cout << dist[x2][y2] << endl;
}
