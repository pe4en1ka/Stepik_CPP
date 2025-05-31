#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, min;
    cin >> n;
    vector <int> v;
    // считывание
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp % 2 == 1 || tmp % 2 == -1) {
            v.push_back(tmp);
        }
    }
    if (v.empty()) {
        cout << 0;
        return 0;
    }
    min = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < min) {
            min = v[i];
        }
    }
    cout << min;
    return 0;
}