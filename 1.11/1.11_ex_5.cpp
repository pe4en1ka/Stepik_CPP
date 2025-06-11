#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    map <string, string> dict_f;
    map <string, string> dict_s;
    for (int i = 0; i < n; i++) {
        string word, sin;
        cin >> word >> sin;
        dict_f[word] = sin;
        dict_s[sin] = word;
    }
    string word;
    cin >> word;
    if (dict_f.find(word) != dict_f.end()) {
        cout << dict_f[word];
    }
    else {
        cout << dict_s[word];
    }
    return 0;
}