#include <iostream>
#include <string>
using namespace std;

int main() {
    char num;
    cin >> num;
    if (num >= '0' && num <= '9') {
        cout << "yes";
    }
    else {
        cout << "no";
    }
    return 0;
}