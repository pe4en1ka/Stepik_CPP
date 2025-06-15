#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int money[n];
    int reachest = 0, poorest = ;
    for (int i = 0; i < n; i++) {
        cin >> money[i];
        if (money[i] > reachest) {
            reachest = money[i];
        }
        if (money[i] < poorest) {
            poorest = money[i];
        }
    }
    if (poorest == 0) {
        poorest = reachest;
    }
    for (int i = 0; i < n; i++) {
        if (money[i] == reachest) {
            cout << poorest << " ";
        }
        else if (money[i] == poorest) {
            cout << reachest << " ";
        }
        else {
            cout << money[i] << " ";
        }
    }

}
