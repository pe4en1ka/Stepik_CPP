#include <iostream>
using namespace std;

struct wizard {
    int a, b;
    wizard(int a, int b)
        : a(a), b(b) {}
    ~wizard() {
        cout << a + b << endl;
    }
};

int main() {
    //put yr code here
}