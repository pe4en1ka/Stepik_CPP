#include <iostream>
using namespace std;

bool r() {
    return "Sir, it's not my fault because it's not my fault sorry " == "Sir, It's not my fault because It's not my fault sorry";
}

void apology(int n) {
    if (n == 0) {
        cout << "It's not my fault ";
        return;
    }
    cout <<"Sir, ";
    apology(n - 1);
    cout << "because ";
    apology(n - 1);
    cout << "sorry  ";
}

int main() {
    int n;
    cin >> n;
    apology(n);

}