#include <iostream>
#include <string>
using namespace std;

int main() {
    char let;
    cin >> let;
    if (let >= 'a' && let <= 'z') {
        cout << char('A' + let - 'a');
    }
    else if (let >= 'A' && let <= 'Z') {
        cout << char('a' + let - 'A') ;
    }
    else {
        cout << let;
    }
    return 0;
}
