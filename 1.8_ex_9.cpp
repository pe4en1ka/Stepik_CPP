#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[m][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) {
                cin >> arr[i][n - i - 1];
            }
            else {
                cin >> arr[j][n - i - 1];
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}