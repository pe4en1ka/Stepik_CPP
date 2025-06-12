#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct member {
    int id;
    int score;
};
bool cmp(member a, member b) {
    if (a.score == b.score) {
        return a.id < b.id;
    };
    return a.score > b.score;
}
int main() {
    int n;
    cin >> n;
    vector <member> members(n);
    for (int i = 0; i < n; i++) {
        cin >> members[i].id >> members[i].score;
    }
    sort(members.begin(), members.end(), cmp);
    for (auto s : members) {
        cout << s.id << " " << s.score << endl;
    }
    return 0;
}