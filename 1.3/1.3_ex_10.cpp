#include <iostream>
using namespace std;
int main()
{
    int sts, h, m, m1, m2, sec, sec1, sec2;
    cin >> sts;
    h = (sts / 3600) % 24;
    m = sts % 3600 / 60;
    m1 = m / 10;
    m2 = m % 10;
    sec = sts % 3600 % 60;
    sec1 = sec / 10;
    sec2 = sec % 10;
    cout << h << ":" << m1 << m2 << ":" << sec1 << sec2;
    return 0;
}
