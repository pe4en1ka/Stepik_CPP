#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<bool> a(n, false);
    for (int i = 0; i < n; i++) {
        char tmp;
        cin >> tmp;
        if (tmp == 2) {
            a[i] = true;
        }
    }
    int max = 0, cnt1 = 0, cnt2 = 0;
    bool cur = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] == cur) {
            if (cur == false) {
                cnt1++;
            }
            else {
                cnt2++;
            }
            continue;
        }
        else {
            if ()
            cur = a[i];
            if (cur == false) {
                cnt1++;
            }
            else {
                cnt2++;
            }
        }
    }
}