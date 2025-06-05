#include <iostream>
using namespace std;

int main() {
    int n, fib1 = 0, fib2 = 1,cnt = 1, tmp = 0;
    cin >> n;
    while (cnt != n) {
        tmp = fib2;
        fib2 = fib1 + fib2;
        fib1 = tmp;
        cnt++;
    }
    cout << fib2;
}
