#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m, cnt = 0;
    cin >> n;
    set <int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.insert(num);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int tmp = 0;
        cin >> tmp;
        auto it = nums.find(tmp);
        if (it != nums.end()) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
