#include <iostream>
using namespace std;

int dist(int &a, int &b) {
    int *i = &a;
    int *j = &b;
    return abs(j - i) + 1;
}

int main() {
    int n, i, j;
    cin >> n >> i >> j;
    int a[n];
    cout << dist(a[i], a[j]);
}