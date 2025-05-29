#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double x;
    cin >> x;
    cout << (x - trunc(x)) * 10 - ((x - trunc(x)) * 10 - trunc((x - trunc(x)) * 10));
}