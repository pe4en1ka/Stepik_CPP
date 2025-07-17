#include <bits/stdc++.h>
using namespace std;
#define ll long long

constexpr int MAXN = 100500;
int a[MAXN];
ll dp[MAXN];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) { // Считывание массива
        cin >> a[i];
    }
    dp[0] = 0;
    dp[1] = a[1];
    dp[2] = 
}