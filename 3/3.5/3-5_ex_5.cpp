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

    for (int i = 0; i < n; i++) {
        
    }

    vector <pair <long double, int>> ben(n);
    for (int i = 0; i < n; i++) {
        ben[i].first = static_cast<double>(c[i] / w[i]);
        ben[i].second = i;
    }
    sort(ben.begin(), ben.end(), comppair);
    int cnt = 0, wei = 0;
    for (int i = 0; i < n; i++) {
        int cur_w = w[ben[i].second];
        int cur_c = c[ben[i].second];
        if (s >= wei + cur_w ) {
            cnt += cur_c;
        }
        else {

        }
    }
}