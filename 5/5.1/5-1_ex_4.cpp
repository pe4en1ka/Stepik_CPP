#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unsigned int n, m;
    cin >> n >> m;
    int i = m;
    while (i > 0) {
        unsigned int tmp;
        cin >> tmp;
        if (1 <= tmp && tmp <= n) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
        i--;
    }
}