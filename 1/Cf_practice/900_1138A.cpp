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
        if (tmp == 50) {
            a[i] = true;
        }
    }
    int maxx = 0, cnt1 = 0, cnt2 = 0; auto l1 = distance(a.begin(),find(a.begin(), a.end(), false)), l2 = distance(a.begin(), find(a.begin(), a.end(), true));
    bool cur = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] == cur) {
            if (cur == false) {
                l1 = i;
                cnt1++;
            }
            else {
                l2 = i;
                cnt2++;
            }
            continue;
        }
        else {
            if (cnt1 >= cnt2 || cnt1 <= cnt2) {
                maxx = max(2 * min(cnt1, cnt2),maxx);
            }
            cur = a[i];
            if (cur == false) {
                if (l1 != i) {
                    cnt1 = 0;
                }
                cnt1++;
            }
            else {
                if (l2 != i) {
                    cnt2 = 0;
                }
                cnt2++;
            }
        }
    }
    if (cnt1 >= cnt2 || cnt1 <= cnt2) {
        maxx = max(2 * min(cnt1, cnt2),maxx);
    }
    cout << maxx << endl;
}