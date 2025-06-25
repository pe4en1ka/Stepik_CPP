#include <iostream>
using namespace std;

long long mod;

struct Int {
    long long val;
    Int()
        : val(0) {}
    Int(int a)
        : val((a % mod + mod) % mod) {}
};
Int operator + (Int a, Int b)  {
        long long sum =  a.val + b.val;
        Int s = (sum % mod + mod) % mod;
        return s;
    }

    Int operator - (Int a, Int b)  {
        long long diff = a.val - b.val;
        Int d = (diff % mod + mod) % mod;
        return d;
    }

    Int operator * (Int a, Int b)  {
        long long mult = a.val * b.val;
        Int m = (mult % mod + mod) % mod;
        return m;
    }
int main() {
    //put yr code here
}