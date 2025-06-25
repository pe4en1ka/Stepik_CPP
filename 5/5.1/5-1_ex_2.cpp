#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int i = n - 1;
    while (i >= 0) {
        cout << n - i << " ";
        i--;
    }
}