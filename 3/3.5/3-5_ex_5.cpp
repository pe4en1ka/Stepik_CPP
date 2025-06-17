#include <iostream>
using namespace std;

int duna(int n, int cnt) {
    int c;
    cnt++;
    if (n < 3) {
        return 0;
    }
    else {
        c += duna(n - 1, cnt);
        c += duna(n - 2);
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    cout << duna(n);
}