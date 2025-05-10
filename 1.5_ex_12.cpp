#include <iostream>
using namespace std;

int main() {
    int n, i = 1, pre, res = 0;
    cin >> n;
    while (n != 0) {
        pre = n;
        cin >> n;
        if (pre == n) {
            i++;
        }
        else {
            if (res < i) {
                res = i;
                i = 1;
            }
            else {
                 i = 1;
            }

        }
    }
    cout << res;
    return 0;
}
