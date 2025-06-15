#include <iostream>
using namespace std;

int main() {
    long double a, b;
    cin >> a >> b;
    cout.setf(ios::fixed);
    cout.precision(0);
    cout << a / b;
}