#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, min = 0;
    cin >> n;
    vector <int> v;
    // считывание
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > 0) {
            v.push_back(tmp);
        }
    }
    min = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < min) {
            min = v[i];
        }
    }
    cout << min;
}