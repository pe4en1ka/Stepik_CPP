#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (bool(a > b) + bool(a > c) + bool(a > d) + bool(b > c) + bool(b > d) + bool(c > d));
}