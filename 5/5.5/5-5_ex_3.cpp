#include <iostream>
using namespace std;

int main() {
    double d;
    cin >> d;
    long long *l = reinterpret_cast<long long*> (&d);
    printf("%lld", *l);
}