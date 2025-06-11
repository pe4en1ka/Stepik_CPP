#include <iostream>
#include <string>
using namespace std;

int main() {
    string let;
    int cnt = 1;
    getline(cin, let);
    for (int i = 0; i < let.length(); i++) {
        if (let[i] == ' ') {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}