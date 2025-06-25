#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int i = n - 1;
    while (i >= 0) {
        cout << n - i << '\n';
        i--;
    }
}