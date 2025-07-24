#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1000500;
int a[MAXN];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    a[1] = 0;
    for (int i = 2; i <= n; i++) {
        a[i] = a[i - 1] + 1;
        if (i % 2 == 0) {
            a[i] = min(a[i], a[i / 2] + 1);
        }
        if (i % 3 == 0) {
            a[i] = min(a[i], a[i / 3] + 1);
        }
    }
    cout << a[n];
}