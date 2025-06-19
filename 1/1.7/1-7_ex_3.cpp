#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    double x = (-b + sqrt((pow(b, 2) - 4*a*c)))/(2*a);
    cout.setf(ios::fixed);
    cout.precision(10);
    cout << x;
}