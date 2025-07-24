#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    ull ans = 1, pre = 1, prepre = 1;
    for (int i = 2; i <= 2 * n + 1; i++) {
        ans = pre + prepre;
        prepre = pre;
        pre = ans;
    }
    cout << ans;
}