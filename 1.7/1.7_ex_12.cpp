#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (v.size() == 1) {
        cout << v[0];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i] != v[j]) {
                cnt++;
                if (cnt == n - 1) {
                    cout << v[i] << " ";
                }
            }
        }
        cnt = 0;
    }
    return 0;
}