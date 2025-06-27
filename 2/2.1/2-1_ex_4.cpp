#include <iostream>
using namespace std;

int main () {
    int k1, k2, v1, v2;
    cin >> k1 >> k2;
    cin >> v1 >> v2;
    cout << bool(!((k1 < v1) && (k1 < v2) && (k2 < v1) && (k2 < v2)));
}
