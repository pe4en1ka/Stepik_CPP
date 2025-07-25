#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int t = 240 - k;
    int l = 0;
    int r = n + 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (t > (1 + mid) * mid / 2 * 5) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << r << endl;
}