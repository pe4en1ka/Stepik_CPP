#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull a, b, c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b >> c;
    ull mult = a * b * c;
    ull sum = a * b + b * c + a * c;
    cout << mult / sum;
}