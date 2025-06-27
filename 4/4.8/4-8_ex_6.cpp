#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string a, b, c, tmp;
    cin >> a >> b >> c;
    string s1, s2, s3, s4, s5, s6;
    s1 = a + b + c;
    s2 = a + c + b;
    s3 = b + a + c;
    s4 = b + c + a;
    s5 = c + a + b;
    s6 = c + b + a;
    string res = min({s1, s2, s3,s4,s5,s6});
    cout << res;
}