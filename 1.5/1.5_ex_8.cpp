#include <iostream>
using namespace std;

int main() {
    int n, i = 1, max;
    cin >> n;
    max = n;
    while (n != 0) {
        cin >> n;
        if (max < n){
            max = n;
            i = 1;
        }
        else if (max == n) {
            i++;
        }
    }
    cout << i;
    return 0;
}