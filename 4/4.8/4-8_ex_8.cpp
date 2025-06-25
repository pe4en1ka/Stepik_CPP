#include <iostream>
#include <vector>
using namespace std;

struct team {
    string name;
    int h_lvl, l_lvl, e_lvl, t_lvl, ap_lvl;

    team ()
        : name(""), h_lvl(0), l_lvl(0), e_lvl(0), t_lvl(0), ap_lvl(0) {}

    team (string n, int h, int l, int e, int t, int ap)
        : name(n), h_lvl(h), l_lvl(l), e_lvl(e), t_lvl(t), ap_lvl(ap) {}
    static int sum (team t) {
        return t.h_lvl + t.l_lvl + t.e_lvl + t.t_lvl + t.ap_lvl;
    }
    static void name_sort( vector <team> &vec) {
        int n = static_cast<int> (vec.size());
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < n - i -1; j++) {
                if (vec[j].name > vec[j+ 1].name) {
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
                if (sum(vec[j]) > sum(vec[j+ 1])) {
                    swap(vec[j], vec[j +1]);
                    swapped = true;
                }
                else if (sum(vec[j]) == sum(vec[j + 1])) {
                    if (vec[j].name < vec[j + 1]. name) {
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
};
void to_final(vector <team> t, int k) {
    
}

int main() {
    //put yr code here
}