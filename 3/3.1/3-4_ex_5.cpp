#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 500500; //Константы
bool a[2 * MAXN]; int dp[2 * MAXN]; //Массивы
int n, k;
string seq;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    cin >> seq;
    if (seq[n - 1] == '1') {
        cout << 0;
        return 0;
    }                           // Проверка на невозможность
    for (int i = 0; i < n; i++) {
        char c = seq[i];
        if (c == '1') {
            a[i + k] = true;
        }
        else {
            a[i + k] = false;
        }
    }                           // Конвертация строки в массив
    dp[k - 1] = 1;              // База
    int sl_win = 1;             // Начальное скользящее окно
    for (int i = k; i < n + k; i++) { // Порядок
        dp[i] = sl_win;         // Формула с исп. скользящего окна
        if (a[i]) {
            dp[i] = 0;
        }
        sl_win = (sl_win % MOD - dp[i - k] % MOD) % MOD;
        sl_win = (sl_win % MOD + dp[i] % MOD) % MOD;
    }
    cout << dp[n + k - 1];      // Ответ
}