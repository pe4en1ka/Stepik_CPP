#include <iostream>
using namespace std;

int main() {
    int a1, b1, c1, a2, b2, c2, l1, w1, h1, l2, w2, h2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    l1 = a1;
    w1 = b1;
    h1 = c1;
    l2 = a2;
    w2 = b2;
    h2 = c2;
    if (a1 >= b1 && a1 >= c1) {
        l1 = a1;
        if (b1 >= c1) {
            w1 = b1;
            h1 = c1;
        } else {
            w1 = c1;
            h1 = b1;
        }
    }
    else if (b1 >= a1 && b1 >= c1) {
        l1 = b1;
        if (a1 >= c1) {
            w1 = a1;
            h1 = c1;
        } else {
            w1 = c1;
            h1 = a1;
        }
    }
    else {
        l1 = c1;
        if (a1 >= b1) {
            w1 = a1;
            h1 = b1;
        }
        else {
            w1 = b1;
            h1 = a1;
        }
    }
    if (a2 >= b2 && a2 >= c2) {
        l2 = a2;
        if (b2 >= c2) {
            w2 = b2;
            h2 = c2;
        }
        else {
            w2 = c2;
            h2 = b2;
        }
    }
    else if (b2 >= a2 && b2 >= c2) {
        l2 = b2;
        if (a2 >= c2) {
            w2 = a2;
            h2 = c2;
        }
        else {
            w2 = c2;
            h2 = a2;
        }
    }
    else {
        l2 = c2;
        if (a2 >= b2) {
            w2 = a2;
            h2 = b2;
        }
        else {
            w2 = b2;
            h2 = a2;
        }
    }
    if (l1 == l2 && w1 == w2 && h1 == h2) {
        cout << "Boxes are equal";
    }
    else if ((l1 > l2 && w1 >= w2 && h1 >= h2) || (l1 >= l2 && w1 > w2 && h1 >= h2) || (l1 >= l2 && w1 >= w2 && h1 > h2))  {
        cout << "The first box is larger than the second one";
    }
    else if ((l1 < l2 && w1 <= w2 && h1 <= h2) || (l1 <= l2 && w1 < w2 && h1 <= h2) || (l1 <= l2 && w1 <= w2 && h1 < h2)) {
        cout << "The first box is smaller than the second one";
    }
    else {
        cout << "Boxes are incomparable";
    }
    return 0;
}
