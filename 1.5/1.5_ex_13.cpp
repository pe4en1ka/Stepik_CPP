#include <iostream>
using namespace std;

int main() {
    int n, pre = 0, prepre = 0, cnt = 0;
    cin >> n;
    while (n != 0) {
        if (pre > prepre && pre > n && pre != 0 && prepre != 0 && n != 0) {
            cnt++;
        }
        prepre = pre;
        pre = n;
        cin >> n;
    }
    cout << cnt;
    return 0;
}
