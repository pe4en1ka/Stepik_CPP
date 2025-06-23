#include <iostream>
using namespace std;

void ras(string &s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'e') {
            s.erase(i, 1);
            i--;
        }
    }
}

int main() {
    string s = "eeeae";
    ras(s);
    cout << s;
 }