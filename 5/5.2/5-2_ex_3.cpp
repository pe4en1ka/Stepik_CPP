#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    short int k;
    cin >> n >> k;
    vector <char> ka;
    while (n >= k) {
        int tmp = n % k;
        char dig;
        if ( 0 <= tmp && tmp <= 9) {
            dig = char(48 + tmp);
        }
        else if (10 <= tmp * tmp <= 36) {
            dig = char(65 + tmp - 10);
        }
        ka.push_back(dig);
        n /= k;
    }
    if ( 0 <= n && n <= 9) {
        cout << char(48 + n);
    }
    else if (10 <= n && n <= 36) {
        cout << char(65 + n - 10);
    }
    for (int i = static_cast<int> (ka.size()) - 1; i >= 0; i--) {
        cout << ka[i];
    }
}