#include <iostream>
using namespace std;

int cnt = 0;
void sum() {
    int n;
    cin >> n;
    if (n != 0) {
        cnt += n;
        sum();
    }
    else {
        cout << cnt;
    }
}
int main() {
    sum();
}
