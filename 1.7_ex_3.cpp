#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, cnt = 0;
    cin>>n;
    vector <int> v;
    // считывание
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > 0) {
            cnt++;
        }
    }
    // вывод
    cout << cnt;
    return 0;
}