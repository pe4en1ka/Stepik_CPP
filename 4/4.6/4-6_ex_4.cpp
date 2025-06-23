#include <iostream>
#include <vector>
using namespace std;

int el_sum(const vector <int>& vec) {
    int sum = 0;
    for (auto i : vec) {
        sum += i;
    }
    return sum;
}

void sort_vector(vector < vector<int> >& v) {
    int n = (int)v.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            // Сравниваем соседние элементы
            if (el_sum(v[j]) > el_sum(v[j + 1])) {
                swap(v[j], v[j + 1]);  // Меняем местами
                swapped = true;
            }
        }
        // Если обменов не было - массив отсортирован
        if (!swapped) break;
    }
}

int main() {
    //put yr code here
}