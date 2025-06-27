#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    short int n;
    cin >> n;
    if (! (a & (1 << n + 1))) {
        a ^= (1 << n);
    }
    cout << a;
}