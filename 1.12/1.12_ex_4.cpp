#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return sqrt(pow(p1.first, 2) + pow(p1.second, 2)) < sqrt(pow(p2.first, 2) + pow(p2.second, 2));
}

int main() {
    int n;
    cin >> n;
    vector <pair <int, int>> coords(n);
    for (int i = 0; i < n; i++) {
        cin >> coords[i].first >> coords[i].second;
    }
    sort(coords.begin(), coords.end(), cmp);
    for (auto p : coords) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
