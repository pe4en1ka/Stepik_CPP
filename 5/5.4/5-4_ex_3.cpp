#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    short int cnt = 0;
    cin >> n;
    long long m = n;
    vector <bool> bin;
    while (m >= 2) {
        bin.insert(bin.begin(), m % 2);
        m /= 2;
    }
    bin.insert(bin.begin(), m);
    auto bits = static_cast<long long>(bin.size());
    for (int i = 0; i < bits; i++) {
        if (n & (1LL << i)) {
            cnt++;
        }
    }
    cout << cnt;
}