#include <iostream>
using namespace std;

int main() {
    int A, fib1 = 0, fib2 = 1,cnt = 1, tmp = 0;
    cin >> A;
    while (fib2 != A) {
        if (fib2 > A) {
            cout << -1;
            return 0;
        }
        tmp = fib2;
        fib2 = fib1 + fib2;
        fib1 = tmp;
        cnt++;
    }
    cout << cnt;
    return 0;
}

