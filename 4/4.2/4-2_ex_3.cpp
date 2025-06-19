#include <iostream>
using namespace std;

void f(int &a, int &b, int &c) {
    c = 2 * b - a;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    f(a, b, c);
    cout << a << ' ' << b << ' ' << c;
}