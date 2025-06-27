#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m = n;
    vector <bool> bin;
    while (m >= 2) {
        bin.insert(bin.begin(), m % 2);
        m /= 2;
    }
    bin.insert(bin.begin(), m);
    int bits = static_cast<int>(bin.size());
    for (int i = 0; i < bits; i += 2) {
        if (! (n & (1 << i))) {
            n |= (1 << i);
        }
    }
    cout << n;
}