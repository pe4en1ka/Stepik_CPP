#include <bits/stdc++.h>
#include <string>
using namespace std;

const string max_year = "87654321";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string cur;
    cin >> cur;
    int ans = -1;
    if (stoi(cur) >= stoi(max_year)) {
        cout << -1;
        return 0;
    }
    int num = stoi(cur) + 1;
    cur = to_string(num);
    int max_y = stoi(max_year);
    bool apr_zt = false;
    bool apr_r = false;
    while (num < max_y) {
        for (int i = 0; i < cur.length(); i++) {
            if (cur[i] == '0' || cur[i] == '2') {
                apr_zt = false;
                break;
            }
            else {
                apr_zt = true;
            }
        }
        if (apr_zt) {
            for (int i = 0; i < cur.length(); i++) {
                char el = cur[i];
                int j;
                for (j = 0; j < cur.length(); j++) {
                    if (cur[j] == el && j != i) {
                        apr_r = false;
                        break;
                    }
                }
                if (j == cur.length()) {
                    apr_r = true;
                }
                else { break; }
            }
            if (apr_r) {
                ans = num;
                break;
            }
            else {
                num++;
                cur = to_string(num);
            }
        }
        else {
            num++;
            cur = to_string(num);
        }
    }
    cout << ans;
}
