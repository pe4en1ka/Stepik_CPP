#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, tmp;
    cin >> n;
    vector <int> v(n);
    // считывание
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (v.size() % 2 == 0) {
        for (int j = 1; j < n; j +=2) {
            tmp = v[j - 1];
            v[j - 1] = v[j];
            v[j] = tmp;
        }
    }
    else {
        for (int j = 1; j < n - 1; j +=2) {
            tmp = v[j - 1];
            v[j - 1] = v[j];
            v[j] = tmp;
        }
    }
    for (auto now : v) {
        cout << now << " ";
    }
    return 0;
}