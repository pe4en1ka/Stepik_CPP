#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;
    cout << num / 1000 << (num % 100) / 10 << (num / 100) % 10 << num % 10;
}