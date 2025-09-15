#include <bits/stdc++.h>
using namespace std;
#define ld long double

bool comppair(const pair<ld, int> &a, const pair<ld, int> &b) {
    return a.first > b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int s, n;
    cin >> s >> n;
    vector <int> w(n);
    vector <int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    ld cnt = 0;
    int wei = 0;
    for (int i = 0; i < static_cast<int>(w.size()); i++) {
        if (w[i] == 0) {
            cnt += c[i];
            w.erase(w.begin() + i);
            c.erase(c.begin() + i);
        }
    }

    vector <pair <ld, int>> ben;
    for (int i = 0; i < static_cast<int>(w.size()); i++) {
        ben.emplace_back((static_cast<ld>(c[i]) / w[i]), i);
    }
    sort(ben.begin(), ben.end(), comppair);

    for (auto & i : ben) {
        int cur_w = w[i.second];
        int cur_c = c[i.second];
        if (s >= wei + cur_w ) {
            cnt += static_cast<ld>(cur_c);
            wei += cur_w;
        }
        else if (s > wei) {
            int part = s - wei;
            cnt +=  static_cast<ld>(cur_c) * (static_cast<ld>(part) / cur_w);
            wei += part;
        }
        else {
            break;
        }
    }
    cout << static_cast<int>(ceil(cnt)) << endl;
}