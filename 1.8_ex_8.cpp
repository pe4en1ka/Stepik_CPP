#include <iostream>
using namespace std;

int main() {
    int n, m, k, cnt = 0;
    cin >> n >> m;
    int seats[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> seats[i][j];
        }
    }
    cin >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (seats[i][j] == 0) {
                cnt++;
                if (cnt == k) {
                    cout << i + 1;
                    return 0;
                }
            }
            else {
                cnt = 0;
            }
        }
        cnt = 0;
    }
    cout << 0;
    return 0;
}