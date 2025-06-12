#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

bool cmp(pair< vector <string>, vector <int> > p1, pair< vector <string>, vector <int> > p2) {
    return p1.second[0] + p1.second[1] + p1.second[2] > p2.second[0] + p2.second[1] + p2.second[2];
}

int main() {
    int n;
    cin >> n;
    vector <pair < vector <string>, vector <int> > > grade(n, pair < vector <string>, vector <int> >(2, 3));
    for (int i = 0; i < n; i++) {
        cin >> grade[i].first[0] >> grade[i].first[1] >> grade[i].second[0] >> grade[i].second[1] >> grade[i].second[2];
    }
    stable_sort(grade.begin(), grade.end(), cmp);
    for (auto name : grade) {
        cout << name.first[0] << " " << name.first[1] << endl;
    }
    return 0;
}