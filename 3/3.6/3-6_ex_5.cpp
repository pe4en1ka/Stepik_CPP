#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i < n; i++) {
        if (a[i - 1] > a[i -2] && a[i - 1] > a[i]) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}