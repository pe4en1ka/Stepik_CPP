#include <iostream>
using namespace std;

void merge(int *b_f, int *e_f, int *b_s, int *e_s, int *b_b) {
    while (b_f != e_f && b_s != e_s) {
        if (*b_f < *b_s) {
            *b_b = *b_f;
            b_f++;
        } else {
            *b_b = *b_s;
            b_s++;
        }
        b_b++;
    }
}

int main() {
    int n;
    cin >> n;
    int nn[n];
    for (int i = 0; i < n; i++) {
        cin >> nn[i];
    }
    int q;
    cin >> q;
    int qq[q];
    for (int i = 0; i < q; i++) {
        cin >> qq[i];
    }
    
}