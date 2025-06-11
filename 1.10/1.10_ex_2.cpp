#include <iostream>
#include <string>
using namespace std;

int main() {
    char let;
    cin >> let;
    if (let >= 'a' && let <= 'z') {
        cout << char('A' + let - 'a');
    }
    else {
        cout << let;
    }
    return 0;
}
