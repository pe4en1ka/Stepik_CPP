//          For stepik
//          Made by coder228
#include <bits/stdc++.h>
using namespace std;

vector <pair<int, int>> ducks;
pair <int, int> stock;
vector <char> dir = {'u', 'r', 'd', 'l'};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;
    vector <vector <int>> walls(2 * n + 1, vector <int>(2 * m + 1));
    vector <vector <int>> dist(2 * n + 1, vector <int>(2 * m + 1, -1));
    vector <vector <pair<int, int>>> par(2 * n + 1, vector <pair <int, int>> (2 * m + 1, {0, 0}));
    for (int i = 1; i <= 2 * n + 1; i++) {
        string s;
        getline(cin, s);
        getline(cin, s);
        for (auto j = 0; j < s.length(); j++) {
            char c = s[j];
            if (c == 'D') ducks.push_back({i, j});
            if (c == 'S') stock = {i, j};
            if (c == '|') walls[i][j] = 1;
            if ( c == '-') walls[i][j] = 2;
            if (c == ' ') walls[i][j] = 0;
            if (c == '+') walls[i][j] = -1;
        }
    }
    auto next_ceil = [&](int x, int y, char drctn) {

    };

    auto dfs = [&](const pair <int, int> &ceil) {
        int x1 = ceil.first, y1 = ceil.second;
        queue <pair <int, int>> q;
        dist[x1][y1] = 0;
        par[x1][y1] = {0, 0};
        q.push({x1, y1});
        while (!q.empty()) {
            pair <int, int> c = q.front();
            int x = c.first, y = c.second;
            for (char d : dir) {

            }
        }
    };
}