#include <iostream>
#include <vector>
using namespace std;

int main() {
    int cnt = 0, cnt_x = 0, cnt_y = 0, temp_x = 0, temp_y = 0;
    vector <int> x(8);
    vector <int> y(8);
    for (int i = 0; i < 8; i++) {
        cin >> x[i];
        cin >> y[i];
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (x[i] != x[j] && y[i] != y[j]) {
                cnt_x++;
                cnt_y++;

            }
        }
        if (cnt_x != 7 || cnt_y != 7) {
            cout << "YES";
            return 0;
        }
        cnt_x = 0;
        cnt_y = 0;
        temp_x = x[i];
        temp_y = y[i];
        for (int q = 0; q < 8; q++) {
            if (temp_x + temp_y != x[q] + y[q]) {
                cnt++;
            }
        }
        if (cnt != 7) {
            cout << "YES";
            return 0;
        }
        cnt = 0;
    }
    cout << "NO";
    return 0;
}