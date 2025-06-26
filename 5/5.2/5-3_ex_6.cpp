#include <iostream>
#include <string>
using namespace std;

string toBinary(string n) {
    static const string hex_to_bin[] = {
        "0000", "0001", "0010", "0011",
        "0100", "0101", "0110", "0111",
        "1000", "1001", "1010", "1011",
        "1100", "1101", "1110", "1111"
    };

    string bin;
    bin.reserve(n.size() * 4);

    for (char c : n) {
        if (c >= '0' && c <= '9')
            bin += hex_to_bin[c - '0'];
        else if (c >= 'A' && c <= 'F')
            bin += hex_to_bin[10 + c - 'A'];
        else if (c >= 'a' && c <= 'f')
            bin += hex_to_bin[10 + c - 'a'];
    }
    return bin;
}

string toOct(string bin) {
    if (bin.empty()) return "0";

    string oct;
    int len = static_cast<int>(bin.size());
    int rem = len % 3;
    oct.reserve(len / 3 + 1);

    // Обработка неполной первой тройки
    if (rem == 1) {
        oct += bin[0];
    }
    else if (rem == 2) {
        oct += char('0' + (bin[0]-'0')*2 + (bin[1]-'0'));
    }

    // Обработка полных троек
    for (int i = rem; i < len; i += 3) {
        int digit = (bin[i]-'0')*4 + (bin[i+1]-'0')*2 + (bin[i+2]-'0');
        oct += char('0' + digit);
    }

    // Удаление ведущих нулей
    size_t start = 0;
    while (start < oct.size()-1 && oct[start]=='0')
        start++;
    return oct.substr(start);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string n;
    cin >> n;

    string bin = toBinary(n);
    string oct = toOct(bin);
    cout << oct;
}