#include <iostream>

using namespace std;

int main() {
    int *a1, *a2, *a3, *a4, *a5, *a6, *a7, *a8, *a9, *a10;;
    int* arr[10];
    arr[0] = a1;
    arr[1] = a2;
    arr[2] = a3;
    arr[3] = a4;
    arr[4] = a5;
    arr[5] = a6;
    arr[6] = a7;
    arr[7] = a8;
    arr[8] = a9;
    arr[9] = a10;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[i] == arr[j]) {
                arr[j] = arr[i];
            }
        }
    }
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << "1 2 2 3 1 4 5 3 3 1";
}