#include <iostream>
#include <vector>
using namespace std;

vector <unsigned long long> dec_to_t(unsigned long long dec, int t) {
    vector <unsigned long long> res;
    while (dec >= t) {
        res.push_back(dec % t);
        dec /= t;
    }
    res.push_back(dec);
    return res;
}

unsigned long long power(unsigned long long a, int b) {
    unsigned long long res = 1;
    for (int i = 0; i < b; i++) {
        res *= a;
    }
    return res;
}

unsigned long long k_to_dec(int k, vector <int> v) {
    unsigned long long res = 0;
    for (int i = 0; i < v.size(); i++) {
        res += power(k, static_cast<int>(v.size()) - i - 1) * v[i];
    }
    return res;
}



int main() {
    int k, t;
    cin >> k >> t;
    vector <int> k_num;
    int dig;
    while (cin >> dig) {
        k_num.push_back(dig);
    }
    unsigned long long dec = k_to_dec(k, k_num);
    vector <unsigned long long> t_num = dec_to_t(dec, t);
    for (int i = static_cast<int>(t_num.size()) - 1; i >= 0 ; i--) {
        cout << t_num[i] << " ";
    }
}