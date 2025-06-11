#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    set <int> numbers;
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        numbers.insert(number);
    }
    cout << numbers.size();
    return 0;
}