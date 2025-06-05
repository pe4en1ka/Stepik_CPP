#include <iostream>
using namespace std;
int main()
{
    int h1, m1, sec1, h2, m2, sec2;
    cin >> h1 >> m1 >> sec1 >> h2 >> m2 >> sec2;
    cout << (h2 - h1) * 3600 + (m2 - m1) * 60 + sec2 - sec1;
    return 0;
}
