#include <iostream>
using namespace std;

int main() {
    int a = 1, b = 2, c = 3, d = 4 ,e = 5;
    int *a1 = &a, *a2 = &b, *a3 = &c, *a4 = &d, *a5 = &e, *a6 = NULL, *a7 = NULL, *a8 = NULL, *a9 = NULL, *a10 = NULL;
    int ans = 0;
    if (a1 != 0) { ans++; }
    if (a2 != 0) { ans++; }
    if (a3 != 0) { ans++; }
    if (a4 != 0) { ans++; }
    if (a5 != 0) { ans++; }
    if (a6 != 0) { ans++; }
    if (a7 != 0) { ans++; }
    if (a8 != 0) { ans++; }
    if (a9 != 0) { ans++; }
    if (a10 != 0) { ans++; }
    cout << ans;
}