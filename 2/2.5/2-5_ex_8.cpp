#include <iostream>
using namespace std;

int main() {
    short int n, bac = 0, bum = 0, bacbum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            bacbum++;
        }
        else if (i % 3 == 0 && i % 5 != 0) {
            bac++;
        }
        else if (i % 5 == 0 && i % 3 != 0) {
            bum++;
        }
    }
    cout << bac << " " << bum << " " << bacbum;
}