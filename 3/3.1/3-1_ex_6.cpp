#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < n; i++) {
        if (nums[i] >= 0) {
            if (nums[i] % 2 == 0) {
                cout << nums[i] << " ";
            }
        }
        else {
            if ((nums[i] * -1) % 2 == 0) {
                cout << nums[i] << " ";
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (nums[i] >= 0) {
            if (nums[i] % 2 == 1) {
                cout << nums[i] << " ";
            }
        }
        else {
            if ((nums[i] * -1) % 2 == 1) {
                cout << nums[i] << " ";
            }
        }
    }
}