#include <iostream>
using namespace std;

int main() {
    long long a, sum = 0;
    int n;
    cin >> a >> n;
    for (int i = 0; i <= n; i++) {
        sum = 1 - a * sum;
    }
    cout << sum;
}