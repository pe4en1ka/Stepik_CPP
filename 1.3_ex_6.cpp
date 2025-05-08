#include <iostream>
using namespace std;
int main()
{
    int N, rem, dec, hun;
    cin >> N;
    rem = N % 10;
    dec = N % 100;
    hun = N / 100;
    cout << rem + (dec - rem) / 10 + hun;
    return 0;
}
