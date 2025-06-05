#include <iostream>
using namespace std;
int main()
{
    int n, k, rem;
    cin >> n >> k;
    rem = k - n * (k / n);
    cout << rem;
    return 0;
}
