#include <iostream>
using namespace std;

int main() {
    short int k, n, m;
    cin >> k >> n >> m;
    int arr[k][n][m];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < m; l++) {
                cin >> arr[i][j][l];
            }
        }
    }
    short int q;
    cin >> q;
    short int req[q][3];
    for (int i = 0; i < q; i++) {
        cin >> req[i][0] >> req[i][1] >> req[i][2];
    }
    for (int i = 0; i < q; i++) {
        cout << arr[req[i][0] - 1][req[i][1] - 1][req[i][2] - 1] << endl;
    }
}