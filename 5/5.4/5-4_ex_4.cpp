#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long a;
    cin >> a;
    long long m = a;
    vector <bool> bin;
    while (m >= 2) {
        bin.insert(bin.begin(), m % 2);
        m /= 2;
    }
    bin.insert(bin.begin(), m);
    auto bits = static_cast<long long> (bin.size());
    
    for ()
    cout <<
}