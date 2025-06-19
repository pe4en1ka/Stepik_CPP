#include <iostream>
using namespace std;

int main() {
    short int n, cnt = 0;
    cin >> n;
    short int p[n];
    short int q[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    for (int i = 0; i < n; i++) {
        if (q[i] - p[i] >= 2) {
            cnt++;
        }
    }
    cout << cnt;
}
