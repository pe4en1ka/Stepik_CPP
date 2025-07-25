#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        int cnt = 0;
        int l = 0;
        int r = n + 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (mid * 4 <= n) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        cnt += l;
        n -= cnt * 4;
        l = 0;
        r = n + 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (mid * 2 <= n) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        cnt += l;
        cout << cnt << '\n';
    }
}