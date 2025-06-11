#include <iostream>
#include <string>
using namespace std;

int main() {
    string let;
    cin >> let;
    string ref_let = "";
    for (int i = let.length() - 1; i >= 0;  i--) {
        ref_let += let[i];
    }
    if (ref_let == let) {
        cout << "yes";
    }
    else {
        cout << "no";
    }
    return 0;
}
