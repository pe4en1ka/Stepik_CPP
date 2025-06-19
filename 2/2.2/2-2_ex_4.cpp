#include  <iostream>
using namespace std;

int main() {
    char let;
    cin >> let;
    if ( let >= 'a' && let <= 'z' ) {
        cout << "small";
    }
    else {
        cout << "BIG";
    }
}