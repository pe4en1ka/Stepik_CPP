#include <iostream>
using namespace std;

int main() {
    int n, i;
    cin >> n;
    i = n;
    while (n != 0) {
        cin >> n;
        i += n;
    }
    cout << i;
    return 0;
}
