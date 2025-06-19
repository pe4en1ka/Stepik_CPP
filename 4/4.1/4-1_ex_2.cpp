#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    int *ptr = a + k;
    ptr -= k;
    for (int i = 0; i < n; i++) {
        *ptr = n - i;
        ptr++;
    }
    for (auto i : a) {
        cout << i << " ";
    }


}