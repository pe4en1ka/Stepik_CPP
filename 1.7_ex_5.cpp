#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> v(n);
    // считывание
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int j = 1; j < n; j++) {
        if (v[j - 1] > 0 && v[j] > 0 || v[j - 1] < 0 && v[j] < 0) {
            if (v[j] >= v[j - 1]) {
                cout << v[j - 1] << " " << v[j];
                return 0;
            }
            else {
                cout << v[j] << " " << v[j - 1];
                return 0;
            }
        }
    }
    return 0;
}