#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 200500;
int n, m, req;
int a[MAXN];

int isNumberIn(int x) {
    int l = -1;
    int r = n;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (a[mid] > x) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    if (r == n) {
        return -1;
    }
    else {
        return r + 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> req;
        if (isNumberIn(req) == -1) {
            cout << "NO SOLUTION" << endl;
        }
        else {
            cout << isNumberIn(req) << endl;
        }
    }
}