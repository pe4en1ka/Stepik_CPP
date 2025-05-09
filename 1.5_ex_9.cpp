#include <iostream>
using namespace std;

int main() {
    int n, max, pre_max = 0;
    cin >> n;
    max = n;
    while (n != 0) {
        cin >> n;
        if (max < n) {
            pre_max = max;
            max = n;
        }
        else if (max == n) {
            pre_max = max;
        }
        else if (n < max && n > pre_max) {
            pre_max = n;
        }
    }
    cout << pre_max;
    return 0;
}
