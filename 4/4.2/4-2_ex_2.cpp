#include <iostream>
using namespace std;

bool check(int *uk) {
    return uk == 0;
}

int main() {
    int* a = 0;
    cout << check(a);
}