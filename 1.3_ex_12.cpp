#include <iostream>
using namespace std;
int main()
{
    int v,t, s;
    cin >> v >> t;
    s = v * t;
    cout << (s % 109 + 109) % 109;
    return 0;
}
