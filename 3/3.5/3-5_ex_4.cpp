#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //Ввод данных
    int s, n;
    cin >> s >> n;
    vector <int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    //Инициализация массива дп
    vector <vector <bool>> dp(n + 1, vector <bool>(s + 1,false));
    dp[0][0] = true;    // Базовый случай: без слитков можно набрать вес 0

    //Заполнение массива дп
    for (int i = 1; i <= n; i++) {
        int cur_w = w[i - 1];
        for (int j = 0; j <= s; j++) {
            //Проверяем можно ли набрать вес w без текущего слитка
            if (dp[i - 1][j]) {
                dp[i][j] = true;
            }
            // Проверяем, можно ли набрать вес w с текущим слитком
            else if (j >= cur_w && dp[i - 1][j - cur_w]) {
                dp[i][j] = true;
            }
        }
    }
    //Поиск максимального веса
    int max_w = 0;
    for (int j = s; j >= 0; j--) {
        if (dp[n][j]) {
            max_w = j;
            break;
        }
    }

    vector <int> route;
    int i = n;
    int j = max_w;
    while (i > 0 && j > 0) {
        // Проверяем, был ли взят i-й слиток
        if (j >= w[i - 1] && dp[i - 1][j - w[i - 1]]) {
            route.push_back(i);         // Добавляем номер слитка
            j -= w[i - 1];              // Уменьшаем текущий вес
        }
        i--;    // Переходим к следующему слитку
    }
    //Восстановление порядка номеров слитков
    sort(route.begin(), route.end());

    // Вывод результата
    cout << max_w << " " << route.size() << endl;
    for (size_t q = 0; q < route.size(); q++) {
        if (q > 0) cout << " ";
        cout << route[q];
    }
    cout << endl;
}