#include <iostream>
using namespace std;

int main() {
    int a, cnt = 0;
    cin >> a;
    cnt += bool(a % 2 == 0);
    cin >> a;
    cnt += bool(a % 2 == 0);
    cin >> a;
    cnt += bool(a % 2 == 0);
    cin >> a;
    cnt += bool(a % 2 == 0);
    cin >> a;
    cnt += bool(a % 2 == 0);
    cout << cnt;
}