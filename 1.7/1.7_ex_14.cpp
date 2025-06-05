#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, l, r;
    cin >> n >> k;
    vector <char> v(n, 'I');
    for (int i = 0; i < k; i++) {
        cin >> l >> r;
        for (int j = l - 1; j <= r - 1; j++) {
            v[j] = '.';
        }
    }
    for (char now : v) {
        cout << now;
    }
    return 0;
}