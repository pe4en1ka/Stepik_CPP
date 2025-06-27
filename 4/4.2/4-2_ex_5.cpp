#include <iostream>
using namespace std;

/* Изначальное решение через вайл, меньше памяти, работа только с указателями
 *void merge(int *b_f, int *e_f, int *b_s, int *e_s, int *b_b) {
    while (b_f != e_f + 1 && b_s != e_s + 1) {
        if (*b_f < *b_s) {
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

}*/

//Решение через циклы фор, больше затрат памяти работа не только с указателями
void merge(int *b_f, const int *e_f, int *b_s, const int *e_s, int *b_b) {
    long long n = e_f - b_f + 1;
    long long q = e_s - b_s + 1;
    for (int i = 0; i < n + q; i++) {
        if (*b_f <= *b_s ) {
            *b_b = *b_f;
            b_f++;
            b_b++;
            if (b_f == e_f + 1) {
                break;
            }
        }
        else {
            *b_b = *b_s;
            b_s++;
            b_b++;
            if (b_s == e_s + 1) {
                break;
            }
        }
    }
    n = e_f - b_f + 1;
    q = e_s - b_s + 1;
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
            b_s++;
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
    merge(nn, nn + n - 1, qq, qq + q - 1, buf);
    for (auto i : buf) {
        cout << i << " ";
    }
}