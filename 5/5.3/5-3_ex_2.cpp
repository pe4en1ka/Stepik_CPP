#include <iostream>
using namespace std;

int main() {
    long double n;
    cin >> n;
    if (-128 <= n && n <= 127) { cout << "char" << '\n';}
    if (0 <= n && n <= 255) { cout << "unsigned char" << '\n';}
    if (-32768 <= n && n <= 32767) {cout << "short int" << '\n';}
    if (0 <= n && n <= 65535) {cout << "unsigned short int" << '\n';}
    if (-2147483648 <= n && n <= 2147483647) {cout << "int" << '\n';}
    if (0 <= n && n <= 4294967295) {cout << "unsigned int" << '\n';}
    if (-9223372036854775808 <= n && n <= 9223372036854775807) {cout << "long long" << '\n';}
    if (0 <= n && n <= 18446744073709551615) {cout << "unsigned long long" << '\n';}
}