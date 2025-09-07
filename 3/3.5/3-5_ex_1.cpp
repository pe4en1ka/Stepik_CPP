#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int s, n;
    cin >> s >> n;
    ll w = 0;
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        cin >> tmp;
        w += tmp;
    }
    cout << ((w >= s) ? s : w);
}