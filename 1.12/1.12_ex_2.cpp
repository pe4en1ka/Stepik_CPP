#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 int main () {
     int size, n, cnt = 0;
     cin >> size >> n;
     if (n == 0) {
         cout << 0;
         return 0;
     }
     else {
         vector <int> shoes;
         for (int i = 0; i < n; i++) {
             int sh_size;
             cin >> sh_size;
             if (sh_size >= size) {
                 shoes.push_back(sh_size);
             }
         }
         sort(shoes.begin(), shoes.end());
         int tmp = size - 3;
         for (auto s : shoes) {
             if (s - tmp >= 3) {
                 tmp = s;
                 cnt++;
             }
         }
     }
     cout << cnt;
     return 0;
 }