#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, cnt = 1;
    cin >> n;
    vector <int> v(n);
    // считывание
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int j = 1; j < n; j++) {
        if (v[j - 1] != v[j] ) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}