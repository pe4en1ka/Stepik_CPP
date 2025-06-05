#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, m, cnt = 1;
    cin >> n >> m;
    int arr[n][m];
    for (int d = 0; d < n + m - 1; d++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i + j == d) {
                    arr[i][j] = cnt;
                    cnt++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(4) << arr[i][j];
        }
        cout << endl;
    }
    return 0;
}