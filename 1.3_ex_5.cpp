#include <iostream>
using namespace std;
int main() {
    int N, rem, dec;
    cin >> N;
    rem = N % 10;
    dec = N % 100;
    cout << (dec - rem) / 10;
    return 0;
}
