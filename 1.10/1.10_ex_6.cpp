#include <iostream>
#include <string>
using namespace std;

int main() {
    string sen;
    int max_l = 0;
    string tls = "";
    getline(cin, sen);
    sen += " ";
    string tmp = "";
    for (int i = 0; i < sen.length(); i++) {
        if (sen[i] != ' ') {
            tmp += sen[i];
        }
        else {
            if (tmp.length() > max_l) {
                max_l = tmp.length();
                tls = tmp;
                tmp = "";
            }
            else {
                tmp = "";
            }
        }
    }
    cout << tls;
    return 0;
}
