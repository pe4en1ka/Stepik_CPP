#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 33;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector <vector<int>> a(n, vector<int>(m, 0));
    a[0][0] = 1;
    a[0][1] = 1;
    a[1][0] = 1;
    for (int i = 2; i < m; i++) {
        a[0][i] = a[0][i - 1] * 2;
    }
    for (int i = 2; i < n; i++) {
        a[i][0] = a[i - 1][0] * 2;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            for (int k = 0; k < i; k++) {
                a[i][j] = (a[i][j] % MOD + a[k][j] % MOD) % MOD;
            }
            for (int k = 0; k < j; k++) {
                a[i][j] = (a[i][j] % MOD + a[i][k] % MOD) % MOD;
            }
        }
    }
    cout << a[n - 1][m - 1] << endl;
}