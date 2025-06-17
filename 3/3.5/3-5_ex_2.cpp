#include <iostream>
using namespace std;

void f(int n) {
    if (n == 0) {
        return;
    }
    int num;
    cin >> num;
    f(n - 1);
    cout << num << " ";
}


int main() {
    int n;
    cin >> n;
    f(n);
}