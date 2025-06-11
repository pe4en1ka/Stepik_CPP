#include <iostream>
using namespace std;

int AmntOfActns(int floors, int n = 1) {;
    if (floors == 1) {
        return 0;
    }
    else {
        if ((n + n * n) / 2 >= floors - 1) {
            return n;
        }
        else {
            return AmntOfActns(floors, n + 1);

        }
    }
}
int main() {
    int n;
    cin >> n;
    cout << AmntOfActns(n);
}