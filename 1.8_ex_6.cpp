#include <iostream>
using namespace std;

int main() {
    int n, k, cnt = 0;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                if (k > 0) {
                    if (cnt == n - k) {
                        return 0;
                    }
                    else {
                        cout << arr[i + k][j] << " ";
                        cnt++;
                    }
                }
                else if (k == 0) {
                    cout << arr[i][j] << " ";
                }
                else {
                    if (cnt == n + k) {
                        return 0;
                    }
                    else {
                        cout << arr[i][j - k] << " ";
                        cnt++;
                    }
                }
            }
        }
    }
}