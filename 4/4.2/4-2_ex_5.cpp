#include <iostream>
using namespace std;

/*void merge(int *b_f, int *e_f, int *b_s, int *e_s, int *b_b) {
    while (b_f != e_f && b_s != e_s) {
        if (*b_f < *b_s) {
            *b_b = *b_f;
            b_f++;
            if (b_f == e_f) {
                b_b++;
                break;
            }
        } else {
            *b_b = *b_s;
            b_s++;
            if (b_s == e_s) {
                b_b++;
                break;
            }
        }
        b_b++;
    }
    // Копируем оставшиеся элементы из первого массива
    while (b_f != e_f) {
        *b_b = *b_f;
        b_f++;
        b_b++;
    }

    // Копируем оставшиеся элементы из второго массива
    while (b_s != e_s) {
        *b_b = *b_s;
        b_s++;
        b_b++;
    }

}*/

void merge(int *b_f, int *e_f, int *b_s, int *e_s, int *b_b) {
    long long n = e_f - b_f;
    long long q = e_s - b_s;
    for (int i = 0; i < n + q; i++) {
        if (*b_f <= *b_s ) {
            *b_b = *b_f;
            b_f++;
            b_b++;
            if (b_f == e_f) {
                break;
            }
        }
        else {
            *b_b = *b_s;
            b_s++;
            b_b++;
            if (b_s == e_s) {
                break;
            }
        }
    }
    n = e_f - b_f;
    q = e_s - b_s;
    if (n != 0) {
        for (int i = 0; i < n; i++) {
            *b_b = *b_f;
            b_f++;
            b_b++;
        }
    }
    if (q != 0) {
        for (int i = 0; i < q; i++) {
            *b_b = *b_s;
            b_f++;
            b_b++;
        }
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
    int buf[n + q] = {0};
    merge(nn, nn + n, qq, qq + q, buf);
    for (auto i : buf) {
        cout << i << " ";
    }
}