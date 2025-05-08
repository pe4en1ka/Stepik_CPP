#include <iostream>
using namespace std;
int main()
{
    int N, rem;
    cin >> N;
    rem = N % 2;
    cout << N + 2 - rem;
    return 0;
}
