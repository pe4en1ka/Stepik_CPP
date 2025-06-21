#include <iostream>
using namespace std;

struct vector {
    int v[100001]{};
    int sizee;

    vector(int n) {
        sizee = n;
        for (int i = 0; i < sizee; i++) {
            v[i] = 0;
        }
    }
    vector(int n, int val) {
        sizee = n;
        for (int i = 0; i < sizee; i++) {
            v[i] = val;
        }
    }
    void push_back(int val) {
        v[sizee] = val;
        sizee++;
    }
    void pop_back() {
        sizee--;
    }
    [[nodiscard]] int get(int i) const {
        return v[i];
    }
    [[nodiscard]] int size() const {
        return sizee;
    }
};

int main() {
    auto a = vector(10);
    for (int i = 0; i < 10; i++) {
        int q = a.get(i);
        cout << q << " ";
    }
    cout << endl;
    auto a1 = vector(10, 1);
    for (int i = 0; i < 10; i++) {
        int q = a1.get(i);
        cout << q << " ";
    }
    cout << endl;
    a.push_back(10);
    for (int i = 0; i < 11; i++) {
        int q = a.get(i);
        cout << q << " ";
    }
    cout << endl;
    a.pop_back();
    for (int i = 0; i < 11; i++) {
        int q = a.get(i);
        cout << q << " ";
    }
    cout << endl;
    int el = a.get(3);
    cout << el << endl;
    int s = a.size();
    cout << s;
}