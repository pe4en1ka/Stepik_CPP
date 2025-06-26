#include <iostream>
#include <vector>
#include <map>
using namespace std;



string toBinary(string n) {
    map <char, string> hex_to_bin;
    hex_to_bin['0'] = "0000";
    hex_to_bin['1'] = "0001";
    hex_to_bin['2'] = "0010";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string n;
    cin >> n;
    int i = static_cast<int> (n.size());
    int j = i - 1;
    vector <bool> two(i * 4, false);

}