#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll INF = LLONG_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector <ll> a(n);
    for (int i = k; i < n + k; i++) cin >> a[i];
    vector <pair <ll, int>> dp(n, {INF,-1});
    vector <pair <ll, int>> win(k, {0, -1});
    
}