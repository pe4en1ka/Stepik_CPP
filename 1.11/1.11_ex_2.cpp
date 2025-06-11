#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    set <int>  nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (nums.find(num) == nums.end()) {
            nums.insert(num);
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
    return 0;
}