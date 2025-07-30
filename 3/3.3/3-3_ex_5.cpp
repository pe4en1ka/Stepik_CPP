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
    for (int k = 0; k < m + n - 1; k++) {
        int s = max( )
    }
    cout << a[n - 1][m - 1] << endl;
}