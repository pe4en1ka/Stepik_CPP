#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n % 2 == 1) {
        n--;
    }
    for (int i = n; i > 0; i -= 2) {
        cout << i << " ";
    }
}