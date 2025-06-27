#include <iostream>
#include <vector>
using namespace std;

int main() {
    unsigned long long a;
    cin >> a;
    if (a == 0) {
        cout << 0;
        return 0;
    }
    unsigned long long m = a;
    vector <bool> bin;
    while (m >= 2) {
        bin.insert(bin.begin(), m % 2);
        m /= 2;
    }
    bin.insert(bin.begin(), m);
    auto bits = static_cast<long long> (bin.size());
    unsigned long long res = (1ULL << bits) - 1;
    cout << res - a;
}