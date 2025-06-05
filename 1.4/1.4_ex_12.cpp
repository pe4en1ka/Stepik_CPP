#include <iostream>
using namespace std;
int main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    if (n >= m){
        if (x <= m - x && m >= x){
            if (y <= n - y && n >= y) {
                if (x <= y){
                    cout << x;
                }
                else {
                    cout << y;
                }

            }
            else if (y > n - y && n >= y){
                if (x <= n - y){
                    cout << x;
                }
                else{
                    cout << n - y;
                }
            }
        }
        else if (x > m - x && m >= x){
            if (y <= n - y && n >= y){
                if (m - x <= y){
                    cout << m -x;
                }
                else {
                    cout << y;
                }

            }
            else if (y > n - y && n >= y){
                if (m - x <= n - y){
                    cout << m - x;
                }
                else{
                    cout << n - y;
                }
            }
        }
    }
    else{
        if (x <= n - x && n >= x){
            if (y <= m - y && m >= y) {
                if (x <= y){
                    cout << x;
                }
                else {
                    cout << y;
                }

            }
            else if (y > m - y && m >= y){
                if (x <= m - y){
                    cout << x;
                }
                else{
                    cout << m - y;
                }
            }
        }
        else if (x > n - x && n >= x){
            if (y <= m - y && m >= y){
                if (n - x <= y){
                    cout << n -x;
                }
                else {
                    cout << y;
                }

            }
            else if (y > m - y && m >= y){
                if (n - x <= m - y){
                    cout << n - x;
                }
                else{
                    cout << m - y;
                }
            }
        }
    }

    return 0;
}

