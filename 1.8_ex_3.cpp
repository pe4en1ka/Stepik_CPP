#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    int arr[n][n];
    // заполнение нулями(не потребуется дополнительно заполнять главную диагональ)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }
    // заполнение правого верхнего угла
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cnt = 1;
                for (int k = j + 1; k < n; k++) {
                    arr[i][k] = cnt;
                    cnt++;
                }
            }
        }
    }
    // заполнение левого нижнего угла
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (i == j) {
                cnt = 1;
                for (int k = j - 1; k >= 0; k--) {
                    arr[i][k] = cnt;
                    cnt++;
                }
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