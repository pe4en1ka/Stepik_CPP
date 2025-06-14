#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;
    cout << num / 1000 << ((num % 100) / 10) * -1 << ((num / 100) % 10) * -1 << (num % 10) * -1;
}