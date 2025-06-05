#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector <int> v;
    // считывание
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (i % 2 == 0) {
            v.push_back(tmp);
        }
    }
    // вывод
    for (auto now : v) {
        cout << now << " ";
    }
    return 0;
}