#include <iostream>
using namespace std;
int main(){
    int a, b;
    cin >> a >> b;
    if (a > b) {
        cout << 1;
    }
    if (a == b){
        cout << 0;
    }
    if (b > a){
        cout << 2;
    }
}
