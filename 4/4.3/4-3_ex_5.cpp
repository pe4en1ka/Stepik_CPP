#include <iostream>
using namespace std;

struct node {
    node *next;
    int val;
};

node* merge(node* frst, node* second) {
    // Фиктивная начальная нода для упрощения логики
    node dummy;
    node* current = &dummy;
    dummy.next = nullptr;

    // Основной цикл слияния
    while (frst != nullptr && second != nullptr) {
        if (frst->val <= second->val) {
            current->next = frst;
            frst = frst->next;
        } else {
            current->next = second;
            second = second->next;
        }
        current = current->next;
    }

    // Присоединяем остаток
    if (frst != nullptr) {
        current->next = frst;
    } else {
        current->next = second;
    }

    return dummy.next;
}

int main() {
    int n;
    cin >> n;
    node frst[n];
    for (int i = 0; i < n; i++) {
        cin >> frst[i].val;
        if (i == n - 1) { frst[i].next = nullptr; continue; }
        else { frst[i].next = frst + i + 1; }
    }
    int q;
    cin >> q;
    node second[q];
    for (int i = 0; i < q; i++) {
        cin >> second[i].val;
        if (i == q - 1) { second[i].next = nullptr; continue; }
        else { second[i].next = second + i + 1; }
    }
    node *current = merge(frst, second);
    while (current != nullptr) {
        cout << current -> val << " ";
        current = current -> next;
    }
    cout << endl;
}