#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector <int> v(n);
    // считывание
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // вывод
    for (int j = 1; j < n; j++) {
        if (v[j] > v[j - 1]) {
            cout << v[j] << " ";
        }
    }
    return 0;
}