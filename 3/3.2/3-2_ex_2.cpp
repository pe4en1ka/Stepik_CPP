#include <iostream>
using namespace std;

int main() {
    short int n, m;
    cin >> n >> m;
    int transp[n][m];
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            cin >> transp[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << transp[i][j] << " ";
        }
        cout << endl;
    }
}