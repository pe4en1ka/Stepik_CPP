#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n, c;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int cnt = 0;
        cin >> n >> c;
        vector <ull> a(n);
        cin >> a[0];
        if (a[0] > c) {
            cnt++;
        }
        for (int k = 1; k < n ; k++) {
            int tmp;
            cin >> tmp;
            a[k] = tmp * static_cast<ull>(pow(2,k));
            if (a[k] > c) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}