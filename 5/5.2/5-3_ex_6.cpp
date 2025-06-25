#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string n;
    cin >> n;
    int i = static_cast<int> (n.size());
    int j = i - 1;
    vector <bool> two;
    while (!n.empty()) {
        char dig = n[i - 1];
        int dec;
        vector<bool> tmp(3, false);
        if (dig <= '9') {
            dec = int(dig) - 48;
        }
        else {
            dec = 10 + int(dig) - 65;
        }
        n.pop_back();
        int k = 2;
        while (dec >= 2) {
            tmp[k] = dec % 2;
            dec /= 2;
            k--;
        }
        two[j] = dec; two[j - 1] = tmp[2]; two[j - 2] = tmp[1]; two[j - 3] = tmp[0];
        j -= 4;
    }
    for (auto i : two) {
        cout << i;
    }
}