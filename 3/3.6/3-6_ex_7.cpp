#include <iostream>
using namespace std;

void f(int a, int b) {
    char sym;
    cin >> sym;
    if (sym == '.') {
        return;
    }
    if (a == -1) {
        cout << sym;
        a++;

    }
    else {
        cout << "*" << sym;
    }
    f(a, b);
}

int main() {
    f(-1, -1);
}