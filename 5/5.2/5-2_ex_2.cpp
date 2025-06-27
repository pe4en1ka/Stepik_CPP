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
    string n;
    cin >> n;
    long long i = 0;
    long long dec = 0;
    while (! n.empty()) {
        char dig = n[n.size() - 1];
        int o_o_z;
        if (dig == '0') {
            o_o_z = 0;
        }
        else {
            o_o_z = 1;
        }
        dec += o_o_z * power(2, i);
        n.pop_back();
        i++;
    }
    cout << dec;
}