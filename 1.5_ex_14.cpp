#include<iostream>
using namespace std;

int main(){
    int n, pre = 0, prepre = 0, max1 = 0, max2 = 0, dist = 0, cnt = 1;
    cin >> n;
    while (n != 0) {
        prepre = pre;
        pre = n;
        cin >> n;
        cnt ++;
        if (pre > prepre && pre > n && pre != 0 && prepre != 0 && n != 0){
            if (max1 == 0 || max2 == 0) {
                if (max1 == 0) {
                    max1 = cnt - 1;
                }
                else {
                    max2 = cnt - 1;
                    dist = max2 - max1;
                }
            }
            else {
                max1 = max2;
                max2 = cnt - 1;
                if (dist > max2 - max1){
                    dist = max2 - max1;
                }
            }
        }
    }
    cout << dist;
    return 0;
}