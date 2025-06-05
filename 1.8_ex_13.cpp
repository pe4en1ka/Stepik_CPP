#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, m, cnt = 1, up = 1, left = 0, i = 0, j = 0;
    cin >> n >> m;
    int arr[n][m];
    int down = n;
    int right = m;
    while (cnt <= n * m) {
        while (j < right) {
            if (cnt > n * m) {
                break;
            }
            arr[i][j] = cnt;
            cnt++;
            j++;
        }
        j--;
        i++;
        right--;
        while (i < down) {
            if (cnt > n * m) {
                break;
            }
            arr[i][j] = cnt;
            cnt++;
            i++;
        }
        i--;
        j--;
        down--;
        while (j > left) {
            if (cnt > n * m) {
                break;
            }
            arr[i][j] = cnt;
            cnt++;
            j--;
        }
        left++;
        while (i > up) {
            if (cnt > n * m) {
                break;
            }
            arr[i][j] = cnt;
            cnt++;
            i--;
        }
        up++;

    }
    for (int k = 0; k < n; k++) {
        for (int q= 0; q < m; q++) {
            cout << setw(4) << arr[k][q];
        }
        cout << endl;
    }
    return 0;

}