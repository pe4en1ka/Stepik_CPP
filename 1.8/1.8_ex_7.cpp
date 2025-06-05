#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int transpn_arr[m][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> transp_arr[j][i];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << transp_arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}