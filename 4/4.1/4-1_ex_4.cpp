#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int min = 0;
    int max = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] > a[max]) {
            max = i;
        }
        if (a[i] < a[min]) {
            min = i;
        }
    }
    int ans = a[max] - a[min] + 1;
}