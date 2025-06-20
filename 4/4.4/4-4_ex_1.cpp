#include <iostream>
using namespace std;

struct rectangle {
    int w, h;
    rectangle(int x1, int  y1, int x2, int y2)
    : w(abs(x1 - x2)), h(abs(y1 - y2))
    {}
};

int main() {
    //put yr code here
}