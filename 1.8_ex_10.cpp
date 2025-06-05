#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, m, num = 1;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i % 2 == 1) {
                arr[i][m - j - 1] = num;
                num++;
            }
            else {
                arr[i][j] = num;
                num++;
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
