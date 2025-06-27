#include <iostream>
using namespace std;

int main() {
    int a, cnt = 0;
    cin >> a;
    cnt += bool(a > 0);
    cin >> a;
    cnt += bool(a > 0);
    cin >> a;
    cnt += bool(a > 0);
    cin >> a;
    cnt += bool(a > 0);
    cin >> a;
    cnt += bool(a > 0);
    cout << cnt;
}