#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

ull gsd(ull a, ull b) {
    if (a > b) {
        if (b ==0) {
            return a;
        }
        else {
            return gsd(b, a % b);
        }
    }
    else {
        swap(a, b);
        if (b == 0) {
            return a;
        }
        else {
            return gsd(b, a % b);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ull a, b;
    cin >> a >> b;
    
}