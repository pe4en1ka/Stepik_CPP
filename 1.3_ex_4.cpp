#include <iostream>
using namespace std;
int main()
{
    int N, rem;
    cin >> N;
    rem = N % 10;
    cout << (N - rem) / 10;
    return 0;
}
