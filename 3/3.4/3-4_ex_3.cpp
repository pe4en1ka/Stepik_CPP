#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector <int> a(n + 1, 0);
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
    vector <int> r;
    int x = n;
    while (x >= 1) {
        r.push_back(x);
        if (a[x] == a[x - 1] + 1) {
            x--;
        }
        else if (x % 2 == 0 && a[x] == a[x / 2] + 1) {
            x /= 2;
        }
        else {
            x /= 3;
        }
    }
    cout << r.size() - 1 << '\n';
    for (int i = static_cast<int>(r.size()) - 1; i >= 0; i--) {
        cout << r[i] << " ";
    }
}