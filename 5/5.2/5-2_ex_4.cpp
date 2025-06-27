#include <iostream>
#include <cmath>
using namespace std;

long long power(long long x, long long y) {
    long long res = 1;
    for (long long i = y; i >= 1; i--) {
        res *= x;
    }
    if (y == 0) {
        return 1;
    }
    else {
        return res;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string n;
    short int k;
    cin >> n >> k;
    long long i = 0;
    long long dec = 0;
    while (! n.empty()) {
        char dig = n[n.size() - 1];
        int num;
        if (dig <= '9') {
            num = int(dig) - 48;
        }
        else {
            num = 10 + int(dig) - 65;
        }
        dec += num * power(k, i);
        n.pop_back();
        i++;
    }
    cout << dec;
}