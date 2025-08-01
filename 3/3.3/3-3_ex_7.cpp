#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector <vector<int>> a(n, vector<int>(m, 0));
    vector <vector<int>> le(n, vector<int>(m, 0));
    vector <vector<int>> up(n, vector<int>(m, 0));
    vector <vector<int>> di(n, vector<int>(m, 0));
    a[0][0] = 1;
    if (n > 1) {
        a[1][0] = 1;
    }
    if (m > 1) {
        a[0][1] = 1;
    }
    for (int i = 2; i < n; i++) {
        a[i][0] = (a[i - 1][0] % MOD * 2) % MOD;
    }
    for (int j = 2; j < m; j++) {
        a[0][j] = (a[0][j - 1] % MOD * 2) % MOD;
    }
    for (int i = 1; i < n; i++) {
        up[i][0] = a[i][0];
    }
    for (int j = 1; j < m; j++) {
        le[0][j] = a[0][j];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            le[i][j] = (le[i][j - 1] % MOD + a[i][j - 1] % MOD) % MOD;
            up[i][j] = (up[i - 1][j] % MOD + a[i - 1][j] % MOD) % MOD;
            di[i][j] = (di[i - 1][j - 1] % MOD + a[i - 1][j - 1] % MOD) % MOD;
            a[i][j] = ((le[i][j] % MOD + up[i][j] % MOD) % MOD + di[i][j] % MOD) % MOD;
        }
    }
    cout << a[n - 1][m - 1] << endl;
}