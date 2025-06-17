#include <iostream>
using namespace std;

void strange_sort(int n, int a[]) {
    if (n == 1) {
        if (not sizeof(a) == 0) {
            cout << a[0] << " ";
        }
        return;
    }
    int tmp[n / 2];
    if (n % 2 == 1) {
        cout << a[n / 2] << " ";
        for (int i = n / 2 + 1; i < n; i++) {
            tmp[i - n / 2 - 1] = a[i];
        }
        int m = n;
        m /= 2;
        strange_sort(m, tmp);
        for (int i = 0; i < n / 2; i++) {
            tmp[i] = a[i];
        }
        int q = n;
        q /= 2;
        strange_sort(q, tmp);
    }
    if (n % 2 == 0) {
        cout << a[n / 2 - 1] << " ";
        for (int i = n / 2; i < n; i++) {
            tmp[i - n / 2] = a[i];
        }
        int m = n;
        m /= 2;
        strange_sort(m, tmp);
        int tmp_odd[n / 2 - 1];
        for (int i = 0; i < n / 2 - 1; i++) {
            tmp_odd[i] = a[i];
        }
        int q = n;
        q /= 2;
        strange_sort(q, tmp_odd);
    }
}

int main() {
    int n = 8;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    strange_sort(n, a);
}