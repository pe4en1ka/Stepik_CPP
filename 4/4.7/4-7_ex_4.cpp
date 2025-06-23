#include <iostream>
using namespace std;

int main() {
    string line;
    int amnt = 0, wrds = 0;
    while (getline(cin,line)) {
        if (!line.empty()) {
            line += " ";
            int check = wrds;
            string tmp;
            for (int i = 0; i < line.length(); i++) {
                if (line[i] == ' ' && !tmp.empty() && tmp != " ") {
                    wrds++;
                    tmp = "";
                }
                else if (tmp == " ") {
                    tmp = "";
                }
                else {
                    tmp += line[i];
                }
            }
            if (check - wrds == 0) {
                continue;
            }
            else {
                amnt++;
            }
        }
        else {
            continue;
        }
    }
    cout << amnt << wrds;;
}