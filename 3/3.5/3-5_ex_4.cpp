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
}