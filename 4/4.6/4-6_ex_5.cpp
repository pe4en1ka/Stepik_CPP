#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector <int>& vec1, vector <int>& vec2) {
    int n = (int)vec1.size();
    int m = (int)vec2.size();
    vector <int> result(n + m);
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (vec1[i] < vec2[j]) {
            result[k] = vec1[i];
            i++;
        }
        else {
            result[k] = vec2[j];
            j++;
        }
        k++;
    }
    while (i < n) {
        result[k] = vec1[i];
        i++;
        k++;
    }
    while (j < m) {
        result[k] = vec2[j];
        j++;
        k++;
    }
    return result;
}

int main() {
    //put yr code here
}