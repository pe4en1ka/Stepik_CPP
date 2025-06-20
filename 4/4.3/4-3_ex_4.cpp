#include <iostream>
using namespace std;

struct node {
    node *next;
};

int get(node *q) {
    int cnt = 0;
    while (q != NULL) {
        cnt++;
        q = q->next;
    }
    return cnt;
}

int main() {
    //put yr code here
}