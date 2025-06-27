#include <iostream>
using namespace std;


int main() {
    int n, cnt = 1;
    cin >> n;
    long long fail = 1;
    while (fail > 0) {
        cnt++;
        fail *= n;
    }
    cout << cnt;
}