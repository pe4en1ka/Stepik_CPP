#include <bits/stdc++.h>
#define ll  long long
using namespace std;

constexpr ll MAX = 9223372036854775807;
constexpr ll mod = 1791791791;
ll ar[10000050];
ll cur, a, b;

ll NextRand() {
    cur = (cur * a + b) % mod;
    return cur;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    cin >> cur >> a >> b;
    ll maxa = MAX + 1;
    int i_m = 0;
    for (int i = 0; i < n; i++) {
        ar[i] = NextRand();
        if (ar[i] > maxa) {
            maxa = ar[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (maxa == ar[i]) {
            i_m = i;
            break;
        }
    }
    maxa = -MAX;
    int s_m_i = 0;
    for (int i = 0; i < n; i++) {
        if (i_m != i) {
            if (ar[i] > maxa) {
                maxa = ar[i];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (maxa == ar[i] && i_m != i) {
            s_m_i = i;
            break;
        }
    }
    cout << i_m + 1 << " " << s_m_i + 1;
}