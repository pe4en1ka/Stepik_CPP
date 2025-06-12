#include <iostream>
#include <vector>
using namespace std;

bool is_under_attack(vector <vector <int> > bd,int x, int y) {
    return bd[x][y] == -1;
}
int WaysCounter(int n) {
    int ways = 0;
    vector <vector <int> > board(n, vector <int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

        }
    }
    return ways;
}
int main () {
    int n;
    cin >> n;
    cout << WaysCounter(n);
    return 0;
}
