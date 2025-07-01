#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 100500;
int n, m;
bool a[MAXN];

int get_f_o(int k) {
    int l = -1;
    int r = n;
    int cnt = 0;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (mid < k) {
            l = mid;
        }
        else {
            r = mid;
        }
        cnt++;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        cout << get_f_o(k) << '\n';
    }
}