#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    multiset <int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.insert(num);
    }
    cin >> m;
    multiset <int> check;
    for (int i = 0; i < m; i++) {
        int tmp = 0;
        cin >> tmp;
        check.insert(tmp);
    }
    for (auto now : check) {
        if (nums.find(now) != nums.end()) {
            cout << now << " ";
        }
    }
    return 0;
}

