#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, m, cnt = 1;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i + j) % 2 == 0 ) {
                arr[i][j] = cnt;
                cnt++;
            }
            else {
                arr[i][j] = 0;
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