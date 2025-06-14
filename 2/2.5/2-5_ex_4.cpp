#include <iostream>
using namespace std;

int main () {
    int cnt = 0;
    for (int i = 0; i <= 666; ++i) {
        while (i % 6 != 0) {
            i = i + 1;
        }
        cnt++;
        cout << i << " ";
    }
    cout << endl;
    cout << cnt;
}