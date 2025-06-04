#include <iostream>
using namespace std;

int main() {
    int n, m, i, j, temp;
    cin >> n >> m;
    int arr[n][m];
    for (int k = 0; k < n; k++) {
        for (int q = 0; q < m; q++) {
            cin >> arr[k][q];
        }
    }
    cin >> i >> j;
    for (int k = 0; k < n; k++) {
        for (int q = 0; q < m; q++) {
            if (i < j) {
                if (q == i) {
                    temp = arr[k][q];
                    arr[k][q] = arr[k][j];
                }
                else if (q == j) {
                    arr[k][q] = temp;
                }
            }
            else if (i > j) {
                if (q == j) {
                    temp = arr[k][q];
                    arr[k][q] = arr[k][i];
                }
                else if (q == i) {
                    arr[k][q] = temp;
                }
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int q = 0; q < m; q++) {
            cout << arr[k][q] << " ";
        }
        cout << endl;
    }
    return 0;
}