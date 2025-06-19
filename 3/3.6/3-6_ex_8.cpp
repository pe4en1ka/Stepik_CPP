#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, q, cnt = 0;
    cin >> n >> q;
    int items[n];
    int sorted_items[n];
    for (int i = 0; i < n; i++) {
        cin >> items[i];
        sorted_items[i] = items[i];
    }
    sort(sorted_items, sorted_items + n);
    for (int i = 0; i < n; i++) {
        if (sorted_items[i] != items[i]) {
            cnt++;
        }
    }
    for (int i = 0; i < q; i++) {
        int  f, s;
        cin >> f >> s;
        f--;
        s--;
        int a = 0, b = 0;
        if (sorted_items[f] != items[f]) {
            b++;
        }
        if (sorted_items[s] != items[s]) {
            b++;
        }
        swap(items[f], items[s]);
        if (sorted_items[f] != items[f]) {
            a++;
        }
        if (sorted_items[s] != items[s]) {
            a++;
        }
        cnt = cnt - b + a;
        if (cnt == 0) {
            cout << "Sorted!" << "\n";
        }
        else {
            cout << "Unsorted!" << "\n";
        }
    }
}