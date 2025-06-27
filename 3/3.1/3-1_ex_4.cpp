#include <iostream>
using namespace std;

int main() {
    short int n, q;
    cin >> n;
    short int marks[n];
    for (int i = 0; i < n; i++) {
        cin >> marks[i];
    }
    cin >> q;
    short int req[q];
    for (int i = 0; i < q; i++) {
        cin >> req[i];
    }
    for (auto i : req) {
        cout << marks[i - 1] << " ";
    }
}
