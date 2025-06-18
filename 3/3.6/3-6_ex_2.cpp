#include <iostream>
using namespace std;

int f(int a, int b) {
    return a + b;
}

void f_(int a, int b) {
    int c = a + b;
    return;
}

int main() {
    int a = 2, b = 3;
    cout << f(a, b);
}