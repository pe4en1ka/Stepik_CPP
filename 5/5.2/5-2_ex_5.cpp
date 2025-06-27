#include <iostream>
#include <vector>
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
    short int k, t;
    cin >> k >> t >> n;
    long long j = 0;
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
        dec += num * power(k, j);
        n.pop_back();
        j++;
    }

    vector <char> ka;
    while (dec >= t) {
        int tmp = dec % t;
        char dig;
        if ( 0 <= tmp && tmp <= 9) {
            dig = char(48 + tmp);
        }
        else if (10 <= tmp * tmp <= 36) {
            dig = char(65 + tmp - 10);
        }
        ka.push_back(dig);
        dec /= t;
    }
    if ( 0 <= dec && dec <= 9) {
        cout << char(48 + dec);
    }
    else if (10 <= dec && dec <= 36) {
        cout << char(65 + dec - 10);
    }
    for (int i = static_cast<int> (ka.size()) - 1; i >= 0; i--) {
        cout << ka[i];
    }
}