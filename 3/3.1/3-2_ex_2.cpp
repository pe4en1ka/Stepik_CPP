#include <bits/stdc++.h>
using namespace std;
#define ll long long

constexpr int MAXN = 100500;
ll a[MAXN];
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
    dp[2] = dp[1] + a[2];
    if (dp[2] > a[3]) {
        dp[3] = dp[2] + a[3];
    }
    else {
        dp[3] = a[3];
    }
    dp[4] = max(dp[1], dp[3]) + a[4];

    for (int i = 5; i <= n; i++) { // Порядок: по возрастанию i
        dp[i] = max({dp[i-1], dp[i - 3], dp[i - 5]}) + a[i];
    }// Формула

    cout << dp[n];// Ответ
}