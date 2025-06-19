#include <iostream>
using namespace std;

int main() {
    int f, s, th;
    cin >> f >> s >> th;
    if (f <= s) {
        if (s <= th) {
            cout << f << " " << s << " " << th;
        } else {
            if (f <= th) {
                cout << f << " " << th << " " << s;
            } else {
                cout << th << " " << f << " " << s;
            }
        }
    } else {
        if (f <= th) {
            cout << s << " " << f << " " << th;
        } else {
            if (s <= th) {
                cout << s << " " << th << " " << f;
            } else {
                cout << th << " " << s << " " << f;
            }
        }
    }
}

//Лучше всего другой код:
//#include <iostream>
//using namespace std;
//
//int main() {
//    int a, b, c, t;
//    cin >> a >> b >> c;
//    if (b < a) {
//        t = a;
//        a = b;
//        b = t;
//    }
//    if (c < a) {
//        t = a;
//        a = c;
//        c = t;
//    }
//    if (c < b) {
//        t = b;
//        b = c;
//        c = t;
//    }
//    cout << a << " " << b << " " << c <<;
//}
//Он меняет переменные местами, это гораздо лучше
