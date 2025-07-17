#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 100500;
int a[MAXN];
int dp[MAXN];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }//Считывание массива

    dp[0] = 0;
    dp[1] = a[1]; // База

    for (int i = 2; i <= n; i++) {// Порядок: по возрастанию i
        dp[i] = max(dp[i - 1], dp[i - 2]) + a[i];// Формула
    }

    cout << dp[n];// Ответ

}