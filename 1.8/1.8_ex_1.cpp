#include <iostream>
using namespace std;

int main() {
    int n, m, cnt = 0;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int x = n + 1;
    int y = m + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp = arr[i][j];
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < m; l++) {
                    if (temp >= arr[k][l]) {
                        cnt++;
                    }
                }
            }
            if (cnt == n * m) {
                if (i <= x) {
                    if (i == x) {
                        if (j < y) {
                            x = i;
                            y = j;
                        }
                    }
                    else {
                        x = i;
                        y = j;
                    }
                }
            }
            cnt = 0;
        }
    }
    cout << x << " " << y;
}