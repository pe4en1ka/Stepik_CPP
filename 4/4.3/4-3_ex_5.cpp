#include <iostream>
using namespace std;

struct node {
    node *next;
    int val;
};

int* merge(node *frst, node *second) {
    while (frst != NULL && second != NULL) {
        if (frst.val < second.val) {
            *b_b = *b_f;
            b_f++;
            if (b_f == e_f + 1) {
                b_b++;
                break;
            }
        } else {
            *b_b = *b_s;
            b_s++;
            if (b_s == e_s + 1) {
                b_b++;
                break;
            }
        }
        b_b++;
    }
    // Копируем оставшиеся элементы из первого массива
    while (b_f != e_f + 1) {
        *b_b = *b_f;
        b_f++;
        b_b++;
    }

    // Копируем оставшиеся элементы из второго массива
    while (b_s != e_s + 1) {
        *b_b = *b_s;
        b_s++;
        b_b++;
    }
}

int main() {
    //put yr code here
}