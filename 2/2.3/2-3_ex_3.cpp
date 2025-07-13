#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 105;
int n;
int a[MAXN];

int gsd(int a, int b) {
    if (a > b) {
        if (b == 0) {
            return a;
        }
        else {
            return gsd(b, a % b);
        }
    }
    else {
        swap(a, b);
        if (b == 0) {
            return a;
        }
        else {
            return gsd(a, b % a);
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> a[0];
    int nod = a[0];
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        nod = gsd(nod, a[i]);
    }
    cout << nod;
}