#include <iostream>
using namespace std;

void strange_sort(int n, int a[]) {
    if (n <= 0) {
        return;
    }
    if (n <= 1) {
        cout << a[0] << " ";
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
        q--;
        strange_sort(q, tmp_odd);
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    strange_sort(n, a);
}

/* код гораздо круче:
#include <iostream>

using namespace std;

void print_arr(int arr[], int a, int b) {
if (a >= b)
return;

cout << arr[(a + b - 1) / 2] << " ";
print_arr(arr, (a + b + 1) / 2, b);
print_arr(arr, a, (a + b - 1) / 2);
}

int main(void) {
int n;
cin >> n;
int arr[n];
for (int i = 0; i < n; i++) {
cin >> arr[i];
}
print_arr(arr, 0, n);
return 0;
} */
