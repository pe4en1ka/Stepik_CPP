#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int N;
            cin >> N;
            v.resize(N);
        }
        else if (t == 2) {
            int N, val;
            cin >> N >> val;
            v.assign(N, val);
        }
        else if (t == 3) {
            v.clear();
        }
        else if (t == 4) {
            int j;
            cin >> j;
            if (j < 0 || j >= v.size()) {
                cout << "Out of bounds" << endl;
            }
            else {
                cout << v[j] << endl;
            }
        }
        else if (t == 5) {
            cout << v.size() << endl;
        }
        else if (t == 6) {
            int val;
            cin >> val;
            v.push_back(val);
        }
        else if (t == 7) {
            if (not v.empty()) {
                v.pop_back();
            }
        }
        else if (t == 8) {
            int j;
            cin >> j;
            if (not (j < 0 || j >= v.size())) {
                v.erase(v.begin() + j);
            }
        }
        else if (t == 9) {
            int j, val;
            cin >> j >> val;
            v.insert(v.begin() + j + 1, val);
        }
        else if (t == 10) {
            if (not (v.empty())) {
                cout << v[v.size() - 1] << endl;
            }
            else {
                cout << "empty" << endl;
            }
        }
    }
}