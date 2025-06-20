#include <iostream>
using namespace std;

struct node {
    node *next;
    int val;
};

node* merge(node *frst, node *second) {
    node m[20];
    for (int i = 0; i < 20; i++) {
        m[i].val = 0;
        if (i == 19) {m[i].next = nullptr; continue; }
        else {m[i].next = m + i + 1;}
    }
    node *b_m = m;
    b_m = m;
    node *mm = b_m;
    while (frst != nullptr && second != nullptr) {
        if ((frst -> val) <= (second -> val)) {
            (b_m -> val) = (frst -> val);
            frst = frst -> next;
            if (frst == nullptr) {
                b_m = b_m -> next;
                break;
            }
        } else {
            (b_m -> val) = (second -> val);
            second = second -> next;
            if (second == nullptr) {
                b_m = b_m -> next;
                break;
            }
        }
        b_m = b_m -> next;
    }
    // Копируем оставшиеся элементы из первого массива
    while (frst != nullptr) {
        (b_m -> val) = (frst -> val) ;
        frst = frst -> next;
        b_m = b_m -> next;
    }

    // Копируем оставшиеся элементы из второго массива
    while (second != nullptr) {
        (b_m -> val) = (second -> val);
        second = second -> next;
        b_m = b_m -> next;
    }
    return mm;
}

int main() {
    int n;
    cin >> n;
    node frst[n];
    for (int i = 0; i < n; i++) {
        cin >> frst[i].val;
        if (i == n - 1) { frst[i].next = nullptr; continue; }
        else { frst[i].next = frst + i + 1; }
    }
    int q;
    cin >> q;
    node second[q];
    for (int i = 0; i < q; i++) {
        cin >> second[i].val;
        if (i == q - 1) { second[i].next = nullptr; continue; }
        else { second[i].next = second + i + 1; }
    }
    cout << merge(frst, second);
}