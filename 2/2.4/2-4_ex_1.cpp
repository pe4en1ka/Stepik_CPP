#include <iostream>
using namespace std;

 int main() {
     short int n;
     int sum = 0;
     cin >> n;
     for (short int i = 0; i < n + 1; i++) {
         sum += i;
     }
     cout << sum;
 }
