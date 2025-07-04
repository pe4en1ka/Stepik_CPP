#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

constexpr int MAXN = 10050;
ull n, k;
ull a[MAXN];

ull amnt_of_cows(ull dis) {
    int l = 0;
    int r = n - 1;
    for (int i = 1; i < n - 1; i++) {
        if (a[i] - )
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ull l = 0;
    ull r = 10e+9 + 1;
    for (int i = 0; i < 100; i++) {
        ull mid = (l + r) / 2;
        if () {
            l = mid;
        }
        else {
            r = mid;
        }
    }
}