#include <iostream>
using namespace std;

int duna(int n) {
    if (n < 3) {
        return 0;
    }
    else {
        return duna(n - 1) + 1;
    }
}

int main() {
    int n;
    cin >> n;
    cout << duna(n);
}