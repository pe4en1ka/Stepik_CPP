#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 123;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(n, vector <int>(m, 0));
    for  (int i = 0; i < m; i++) {
        if (i % 4 == 0) {
            a[0][i] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i % 4 == 0) {
            a[i][0] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (i >= 2) {
                a[i][j] =(a[i][j] % MOD + a[i - 2][j - 1] % MOD) % MOD;
                if (j + 1 <= m) {
                    a[i][j] =(a[i][j] % MOD + a[i - 2][j + 1] % MOD) % MOD;
                }
            }
            if (j >= 2) {
                a[i][j] = (a[i][j] % MOD + a[i - 1][j - 2] % MOD) % MOD;
                if (i + 1 <= n) {
                    a[i][j] = (a[i][j] % MOD + a[i + 1][j - 2] % MOD) % MOD;
                }
            }
        }
    }
    cout << a[n - 1][m - 1] << endl;
}