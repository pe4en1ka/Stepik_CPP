#include <bits/stdc++.h>
using namespace std;

constexpr int MAXM = 25;
int n, m;
int a[MAXM];

int get_f_o() {
    int l = -1;
    int r = n;
    int i = 0;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (!a[i]) {
            l = mid;
        }
        else {
            r = mid;
        }
        i++;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    cout << get_f_o();
}