#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    ull sum = 0;
    for ( int i = 3; i <= n; i++) {
        if ( i % 2 == 0) {
            sum += 2;
            continue;
        }
        for ( int j = 3; j * j <= i; j += 2) {
            if (i % j == 0) {
                sum += j;
                break;
            }
        }
    }
    cout << sum;
}