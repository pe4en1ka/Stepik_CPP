#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (bool (a != b && a != c && a != d) + bool (b != c && b != d) + bool (c != d) + 1);
}