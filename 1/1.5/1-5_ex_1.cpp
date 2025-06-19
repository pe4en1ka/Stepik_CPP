#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int n;
    long double pi = 3.141592653589793;
    cin >> n;
    cout.setf(ios::fixed);
    cout.precision(n);
    cout << pi;
}