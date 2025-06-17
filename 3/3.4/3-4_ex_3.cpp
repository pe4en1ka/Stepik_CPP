#include <iostream>
using namespace std;

int get_max(int n, int arr[]) {
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[max]) {
            max = i;
        }
    }
    return max;
}

int main() {
    //put yr code here
}