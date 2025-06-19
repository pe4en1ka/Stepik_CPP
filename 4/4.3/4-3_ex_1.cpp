#include <iostream>
using namespace std;

struct rectangle {
    int a, b;
    void set(int s1, int s2) {
        a = s1;
        b = s2;
    }
    int get() {
        return a * a + b * b;
    }
};
int main() {
    int a, b;
    cin >> a >> b;
    rectangle r;
    r.set(a, b);
    cout << r.get() << endl;
}