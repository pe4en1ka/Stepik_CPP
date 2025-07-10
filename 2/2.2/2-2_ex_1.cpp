#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
    int fn_1 = 1, fn_2 = 1;
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        for (int i = 2; i <= n; i++) {
            int fn = fn_1 + fn_2;
            fn_2 = fn_1;
            fn_1 = fn;
        }
        return fn_1;
    }


}

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    cout << fib(n);
}