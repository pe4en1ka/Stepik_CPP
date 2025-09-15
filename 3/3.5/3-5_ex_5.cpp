#include <bits/stdc++.h>
using namespace std;

bool comppair(const pair<int, int> &a, const pair<int, int> &b) {
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
    int cnt = 0, wei = 0;
    for (int i = 0; i < n; i++) {
        if (w[i] == 0) {
            cnt++;
            w.erase(w.begin() + i - 1);
            c.erase(c.begin() + i - 1);
        }
    }

    vector <pair <long double, int>> ben;
    for (int i = 0; i < n; i++) {
        ben.push_back({static_cast<double>(c[i] / w[i]), i});
    }
    sort(ben.begin(), ben.end(), comppair);

    for (int i = 0; i < static_cast<int>(ben.size()); i++) {
        int cur_w = w[ben[i].second];
        int cur_c = c[ben[i].second];
        if (s >= wei + cur_w ) {
            cnt += cur_c;
            wei += cur_w;
        }
        else {
            int part = s - wei;
            cnt +=  cur_c * (part / cur_w);
        }
    }
    cout << ceil(cnt) << endl;
}