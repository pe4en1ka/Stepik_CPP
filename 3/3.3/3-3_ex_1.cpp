#include <iostream>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    int a[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a[n] = t;
    int i = n - 1;
    int m = n;
    while (t <= a[i] && i >= 0) {
        int tmp = a[i];
        a[i] = a[m] ;
        a[m] = tmp;
        i--;
        m--;
    }
    for (int j = 0; j < n + 1; j++ ) {
        cout << a[j] << " ";
    }
}