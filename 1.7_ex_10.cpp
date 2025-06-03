#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, tmp, end;
    cin >> n;
    vector <int> v(n);
    vector <int> a(n);
    // считывание
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    end = v[v.size()- 1];
    for (int j = 0; j < n - 1; j++) {
        a[j + 1] = v[j];
    }
    a[0] = end;
    for (auto now : a) {
        cout << now << " ";
    }
    return 0;
}