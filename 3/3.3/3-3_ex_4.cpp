#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector <vector <bool>> a(n, vector <bool> (m, false));
    vector <vector <ull>> dp(n, vector <ull> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            if (tmp) {
                a[i][j] = true;
            }
        }
    }
    dp[0][0] = 1;
    int ii = 1;
    while (!a[ii][0]) {
        dp[ii][0] = 1;
        ii++;
    }
    for (int i = ii; i < n; i++) {
        dp[i][0] = 0;
    }
    int jj = 1;
    while (!a[0][jj]) {
        dp[0][jj] = 1;
        jj++;
    }
    for (int i = jj; i < m; i++) {
        dp[0][i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

        }
    }
}