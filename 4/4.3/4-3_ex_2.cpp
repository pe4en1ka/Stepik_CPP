#include <iostream>
using namespace std;

struct strange_struct {
    int a, b, c, d, queue;
};

long long f(strange_struct *ss) {
    long long sum;
    sum += (ss->a);
    sum += (ss->b);
    sum += (ss->c);
    sum += (ss->d);
    sum += (ss->queue);
    return sum;
}

int main() {
    //put yr code here
}