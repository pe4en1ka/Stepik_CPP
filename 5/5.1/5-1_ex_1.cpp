#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);

    int n;
    cin >> n;;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        sum += tmp;
    }
    cout << sum;
}