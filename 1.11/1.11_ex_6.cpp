#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    map <string, vector <string> > en_lat_dict;
    map <string, set <string> > lat_en_dict;
    // ввод строк
    for (int i = 0; i <= n; i++) {
        string en;
        getline(cin, en);
        en += " ";
        string tmp_word;
        vector <string> tmp_vec ;
        for (int j = 0; j < en.length(); j++) {
            if (en[j] == ' ' || en[j] == '-' || en[j] == ',') {
                if (not tmp_word.empty()) {
                    tmp_vec.push_back(tmp_word);
                }
                tmp_word = "";
            }
            else {
                tmp_word += en[j];
            }
        }
        for (int j = 1; j < tmp_vec.size(); j++) {
            en_lat_dict[tmp_vec[0]].push_back(tmp_vec[j]);
            lat_en_dict[tmp_vec[j]].insert(tmp_vec[0]);
        }
        tmp_vec.clear();
    }
    // вывод по шаблону
    cout << lat_en_dict.size() << endl;
    for (const auto & item : lat_en_dict) {
        cout << item.first << " - ";
        if (item.second.size() == 1) {
            for (const auto & wrd : item.second) {
                cout << wrd;
            }
        }
        else {
            for (auto it = item.second.begin(); it != item.second.end(); it++) {
                if (it != item.second.begin()) {
                    cout << ", " << *it;
                }
                else {
                    cout << *it;
                }
            }
        }
        cout << endl;
    }
    return 0;
}