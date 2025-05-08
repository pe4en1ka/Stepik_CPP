#include <iostream>
using namespace std;
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c){
        cout << 3;
    }
    if ((a != b && a != c && b == c) || (a != c && b != c && a == b) || (a != b && b != c && a == c) ) {
        cout << 2;
    }
    if (a != b && b != c && a != c){
        cout << 0;
    }
    return 0;
}
