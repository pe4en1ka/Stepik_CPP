#include <iostream>
#include <vector>
using namespace std;

void read(vector<int>& a) {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

int main() {
    vector<int> a;
    read(a);
    for (auto i : a) {
        cout << i << " ";
    }
}