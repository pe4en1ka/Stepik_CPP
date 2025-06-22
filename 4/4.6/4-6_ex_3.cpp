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
            if (j < 0 || j >= n) {
                cout << ""
            }
        }
    }
}