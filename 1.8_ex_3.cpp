#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    int arr[n][n];
    // заполнение нулями(не потребуется дополнительно заполнять главную диагональ)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                arr[i][j] = 0;
            }
            else if (i < j) {
                arr[i][j] = j - i;
            }
            else {
                arr[i][j] = i - j;
            }
        }
    }
    // вывод
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}