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
    vector <vector <int>> walls(2 * n + 1 + 1, vector <int>(2 * m + 1 + 1));
    vector <vector <int>> dist(2 * n + 1 + 1, vector <int>(2 * m + 1 + 1, -1));
    vector <vector <pair<int, int>>> par(2 * n + 1 + 1, vector <pair <int, int>> (2 * m + 1 + 1, {0, 0}));
    string s;
    getline(cin, s);
    for (int i = 1; i <= 2 * n + 1; i++) {
        getline(cin, s);
        for (auto j = 0; j < s.length(); j++) {
            char c = s[j];
            if (c == 'D') {ducks.emplace_back(i, j + 1); walls[i][j + 1] = 5;}
            if (c == 'S') {stock = {i, j + 1}; walls[i][j + 1] = 4;}
            if (c == '|') walls[i][j + 1] = 1;
            if (c == '-') walls[i][j + 1] = 2;
            if (c == '+') walls[i][j + 1] = 3;
            if (c == ' ') walls[i][j + 1] = 0;
        }
    }
    int x2 = stock.first, y2 = stock.second;
    auto next_ceil = [&](const int &x, const int &y, const char &drctn) {
        if (drctn == 'u') {
            for (int i = x; i >= 1; i--) {
                if (walls[i][y] == 2 || walls[i][y] == 3) {pair <int, int> p = {i + 1, y}; return p;}
            }
            pair <int, int> p = {2, y};
            return p;
        }
        else if (drctn == 'r') {
            for (int j = y; j <= 2 * m + 1; j++) {
                if (walls[x][j] == 1 || walls[x][j] == 3) {pair <int, int> p = {x, j - 1}; return p;}
            }
            pair <int, int> p = {x, 2 * m + 1};
            return p;
        }
        else if (drctn == 'd') {
            for (int i = x; i <= 2 * n + 1; i++) {
                if (walls[i][y] == 2 || walls[i][y] == 3) {pair <int, int> p = {i - 1, y}; return p;}
            }
            pair <int, int> p = {2 * n + 1, y};
            return p;
        }
        else {
            for (int j = y; j >= 1; j--) {
                if (walls[x][j] == 1 || walls[x][j] == 3) {pair <int, int> p = {x, j + 1}; return p;}
            }
            pair <int, int> p = {x, 2};
            return p;
        }
    };
    auto dfs = [&](const pair <int, int> &ceil) {
        int x1 = ceil.first, y1 = ceil.second;
        queue <pair <int, int>> q;
        dist[x1][y1] = 0;
        par[x1][y1] = {0, 0};
        q.emplace(x1, y1);
        while (!q.empty()) {
            pair <int, int> c = q.front();
            int x = c.first, y = c.second;
            q.pop();
            for (char d : dir) {
                pair <int, int> nc = next_ceil(x, y, d);
                int nx = nc.first, ny = nc.second;
                dist[nx][ny] = dist[x][y] + 1;
                par[nx][ny] = {x, y};
                q.emplace(nx, ny);
            }
        }
        if (dist[x2][y2] == -1) walls[x2][y2] = 0;
    };
    for (auto duck : ducks) {
        dfs(duck);
    }
    for (int i = 1; i <= 2 * n + 1; i++) {
        for (int j = 1; j <= 2 * m + 1; j++) {
            int z = walls[i][j];
            if (z == 0) cout << " ";
            else if (z == 1) cout << "|";
            else if (z == 2) cout << "-";
            else if (z == 3) cout << "+";
        }
    }
}