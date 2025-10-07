//          For stepik
//          Made by coder228
#include <bits/stdc++.h>
using namespace std;

vector <pair<int, int>> ducks;
pair <int, int> stock;
ve
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;
    vector <vector <int>> walls(2 * n + 1, vector <int>(2 * m + 1));
    vector <vector <int>> dist(2 * n + 1, vector <int>(2 * m + 1, -1));
    vector <vector <pair<int, int>>> par(2 * n + 1, vector <pair <int, int>> (2 * m + 1, {0, 0}));
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= 2 * m; j++) {
            char tmp; cin >> tmp;
            if (tmp == 'D') ducks.push_back({i, j});
            if (tmp == 'S') stock = {i, j};
            if (tmp == '|' or tmp == '-') walls[i][j] = 1;
            if (tmp == ' ') walls[i][j] = 0;
            else walls[i][j] = -1;
        }
    }
    auto dfs = [&](const pair <int, int> &ceil) {
        int x1 = ceil.first, y1 = ceil.second;
        queue <pair <int, int>> q;
        dist[x1][y1] = 0;
        par[x1][y1] = {0, 0};
        q.push({x1, y1});
        while (!q.empty()) {
            pair <int, int> c = q.front();
            int x = c.first, y = c.second;
        }
    };
}