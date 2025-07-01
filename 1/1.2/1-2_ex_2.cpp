#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 1000000500;
int a[100050];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int maxa = -MAX;
    for (int i = 0; i < n; i++) {
        int a_i;
        cin >> a_i;
        a[i] = a_i;
        if (a_i > maxa) {
            maxa = a_i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == maxa) {
            cout << i + 1;
            return 0;
        }
    }
}