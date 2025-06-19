#include <iostream>
using namespace std;

int main() {
    short int n, m;
    cin >> n >> m;
    int earn[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> earn[i][j];
        }
    }
    for (int j = 0; j < m; j++) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += earn[i][j];
        }
        cout << sum << " ";
    }
}