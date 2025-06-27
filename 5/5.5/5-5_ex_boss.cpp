#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define ull unsigned long long

int main() {
    ull a, k, t, ost;
    cin >> k >> t;
    vector <ull> v;
    deque<ull> ans;
    while (cin >> a) {
        v.push_back(a);
    }
    bool ok = true;
    while (ok) {
        ost = 0;
        ok = false;
        for (auto &i : v) {
            ost = (ost *k + i);
            i = ost / t;
            ost = ost % t;
            ok |= i;
        }
        ans.push_front(ost);
    }
    for (auto i : ans) {
        cout << i << " ";
    }
}
