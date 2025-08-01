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
    a[0][0] = 1;
    for (int k = 0; k < m + n - 1; k++) {
        int s = max(0,k - m + 1);
        int e = min(k, n - 1);
        for (int i = s; i <= e; i++) {
            int j = k - i;
            if (i >= 2) {
                if (j >= 1) {
                    a[i][j] = (a[i][j] % MOD + a[i - 2][j - 1] % MOD) % MOD;
                }
                if (j + 1 < m) {
                    a[i][j] = (a[i][j] % MOD + a[i - 2][j + 1] % MOD) % MOD;
                }
            }
            if (j >= 2) {
                if (i >= 1) {
                    a[i][j] = (a[i][j] % MOD + a[i - 1][j - 2] % MOD) % MOD;
                }
                if (i + 1 < n) {
                    a[i][j] = (a[i][j] % MOD + a[i + 1][j - 2] % MOD) % MOD;
                }
            }
        }
    }
    cout << a[n - 1][m - 1] << endl;
}