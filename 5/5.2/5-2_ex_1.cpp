#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    vector <bool> two;
    while (n >= 2) {
        two.push_back(n % 2);
        n /= 2;
    }
    cout << n;
    for (int i = static_cast<int> (two.size()) - 1; i >= 0; i--) {
        cout << two[i];
    }
}