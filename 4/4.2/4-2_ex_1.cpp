#include <iostream>
using namespace std;

void f(int &a){
    a *= 2;
}

int main() {
    int a;
    cin >> a;
    f(a);
    cout << a;
}