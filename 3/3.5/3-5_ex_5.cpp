#include <iostream>
using namespace std;

int duna(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    else {
        return duna(n-1) + duna(n-2);
    }
}

int main() {
    int n;
    cin >> n;
    cout << duna(n) - 1;
}