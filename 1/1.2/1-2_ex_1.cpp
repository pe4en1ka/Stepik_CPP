#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int a;
    ull sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        sum += a;
    }
    cout << sum;
}