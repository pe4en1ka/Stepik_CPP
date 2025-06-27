#include <iostream>
#include <vector>
using namespace std;

struct team {
    string name;
    long h_lvl, l_lvl, e_lvl, t_lvl, ap_lvl;

    team ()
        : name(""), h_lvl(0), l_lvl(0), e_lvl(0), t_lvl(0), ap_lvl(0) {}

    team (string n, int h, int l, int e, int t, int ap)
        : name(n), h_lvl(h), l_lvl(l), e_lvl(e), t_lvl(t), ap_lvl(ap) {}


};
static long long sum (team t) {
        return t.h_lvl + t.l_lvl + t.e_lvl + t.t_lvl + t.ap_lvl;
    }
static void name_sort( vector <team> &vec) {
        int n = static_cast<int> (vec.size());
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < n - i -1; j++) {
                if (vec[j].name > vec[j+1].name) {
                    swap(vec[j], vec[j +1]);
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
    }
static void common_sort(vector <team> &vec) {
        int n = static_cast<int> (vec.size());
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < n - i -1; j++) {
                if (sum(vec[j]) < sum(vec[j+ 1])) {
                    swap(vec[j], vec[j +1]);
                    swapped = true;
                }
                else if (sum(vec[j]) == sum(vec[j+ 1])) {
                    if (vec[j].name > vec[j+1].name) {
                        swap(vec[j], vec[j +1]);
                        swapped = true;
                    }
                }
            }
            if (!swapped) {
                break;
            }
        }
    }
void to_final(vector <team> t, int k) {
        common_sort(t);
        vector <team> t1(k);
        for (int i = 0; i < k; i++) {
            t1[i] = t[i];
        }
        name_sort(t1);
        for (auto i : t1) {
            cout << i.name << " " << i.h_lvl << " " << i.l_lvl << " " << i.e_lvl << " " << i.t_lvl << " " << i.ap_lvl << endl;
        }
}

int main() {
    int mem, fin;
    cin >> mem >> fin;
    vector <team> members(mem);
    for (int i = 0; i < mem; i ++) {
        cin >> members[i].name >> members[i].h_lvl >> members[i].l_lvl >> members[i].e_lvl >>  members[i].t_lvl >> members[i].ap_lvl;
    }
    to_final(members, fin);
}