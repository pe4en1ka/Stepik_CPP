#include <iostream>
#include <string>
using namespace std;

int main() {
    string sen;
    int amnt_f_dts = 0;
    cin >> sen;
    sen += ".";
    string tmp = "";
    if (sen.length() < 7 || sen.length() > 15) {
        cout << "NO";
        return 0;
    }
    for (int j = 0; j < sen.length(); j++) {
        if (sen[j] == '.') {
            amnt_f_dts++;
        }
    }
    if (amnt_f_dts != 4) {
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < sen.length(); i++) {
        if (sen[i] != '.') {
            tmp += sen[i];
        }
        else {
            if (tmp.length() == 0) {
                cout << "NO";
                return 0;
            }
            else if (tmp.length() == 1) {
                if (tmp[0] >= '0' && tmp[0] <= '9') {
                    tmp = "";
                    continue;
                }
                else {
                    cout << "NO";
                    return 0;
                }
            }
            else if (tmp.length() == 2) {
                if (tmp[0] >= '1' && tmp[0] <= '9') {
                    if (tmp[1] >= '1' && tmp[1] <= '9') {
                        tmp = "";
                        continue;
                    }
                    else {
                        cout << "NO";
                        return 0;
                    }
                }
                else {
                    cout << "NO";
                    return 0;
                }
            }
            else if (tmp.length() == 3) {
                if (tmp[0] >= '1' && tmp[0] <= '2') {
                    if (tmp[0] == '2') {
                        if (tmp[1] >= '0' && tmp[1] <= '5') {
                            if (tmp[2] >= '0' && tmp[2] <= '5') {
                                tmp = "";
                                continue;
                            }
                            else {
                                cout << "NO";
                                return 0;
                            }
                        }
                        else {
                            cout << "NO";
                            return 0;
                        }
                    }
                    else {
                        if (tmp[1] >= '0' && tmp[1] <= '9') {
                            if (tmp[2] >= '0' && tmp[2] <= '9') {
                                tmp = "";
                                continue;
                            }
                            else {
                                cout << "NO";
                                return 0;
                            }
                        }
                        else {
                            cout << "NO";
                            return 0;
                        }
                    }
                }
                else {
                    cout << "NO";
                    return 0;
                }
            }
            else if (tmp.length() > 3) {
                cout << "NO";
                return 0;
            }
            else {
                tmp = "";
                continue;
            }
        }
    }
    cout << "YES";
    return 0;
}

