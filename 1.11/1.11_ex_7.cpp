#include <iostream>
#include <set>
#include <string>
#include <map>
using namespace std;
string lower(string s) {
    string lower;
    for (char sym : s) {
        if (sym >= 'A' && sym <= 'Z') {
            lower += char('a' + (sym - 'A'));
        }
        else {
            lower += sym;
        }
    }
    return lower;
}

bool is_correct(string s) {
    int cnt = 0;
    for (char ch : s) {
        if (ch >= 'A' && ch <= 'Z') {
            cnt++;
        }
    }
    if (cnt == 1) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int n, cnt = 0;
    cin >> n;
    map <string, set <string> > dict;
    // создание словаря
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        dict[lower(word)].insert(word);
    }
    string sntnc;
    multiset <string> hw;
    getline(cin, sntnc); // холостой getline
    getline(cin, sntnc);
    if (sntnc.size() == 0) {
        cout << 0;
        return 0;
    }
    sntnc += " ";
    string tmp_word;
    for (char ch : sntnc) {
        if (ch == ' ') {
            hw.insert(tmp_word);
            tmp_word = "";
        }
        else {
            tmp_word += ch;
        }
    }
    // проверка правильности
    for (string word : hw) {
        if (dict.find(lower(word)) != dict.end()) {
            if (dict[lower(word)].find(word) != dict[lower(word)].end()) {
                continue;
            }
            else {
                cnt++;
            }
        }
        else {
            if (not is_correct(word)) {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}