#include <iostream>
#include <string>
using namespace std;

int main() {
    short int b;
    string sen;
    int cost = 0;
    cin >> b;
    getline(cin, sen);
    getline(cin, sen);
    for (int i = 0; i < sen.size(); i++) {
        if (sen[i] >= 'A' && sen[i] <= 'Z') {
            cost += b;
        }
    }
    cout << cost;
}