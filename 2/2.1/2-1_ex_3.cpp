#include <iostream>
using namespace std;

int main() {
    bool a, b, c;
    cin >> a >> b >> c;
    cout << bool((!(!a && b || c) || (b || !a)) && !((c || b) || (b || !a || c)));
}
