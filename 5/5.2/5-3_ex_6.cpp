#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string n;
    cin >> n;

    while (!n.empty()) {
        char dig = n[n.size() - 1];
        int dec;
        vector<int> tmp;
        if (dig <= '9') {
            dec = int(dig) - 48;
        }
        else {
            dec = 10 + int(dig) - 65;
        }

    }
}