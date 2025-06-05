#include <iostream>
using namespace std;
int main(){
    int n, p1, p2, p1n1, p2n1, p1n2, p2n2;
    cin >> n;
    p2 = n % 100;
    p1 = n / 100;
    p1n1 = p1 % 10;
    p1n2 = p1 / 10;
    p2n2 = p2 % 10;
    p2n1 = p2 / 10;
    cout << (p1n1 * 10 + p1n2) - (p2n1 * 10 + p2n2) + 1;
    return 0;
}
