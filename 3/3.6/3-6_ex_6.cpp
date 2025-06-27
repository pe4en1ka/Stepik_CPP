#include <iostream>
using namespace std;

void row(int i_f, char a[8][8]) {
    for (int j = 0; j < 8; j++) {
        if (a[i_f][j] == 'F') {
            continue;
        }
        a[i_f][j] = '!';
    }
}

void col(int j_f, char a[8][8]) {
    for (int i = 0; i < 8; i++) {
        if (a[i][j_f] == 'F') {
            continue;
        }
        a[i][j_f] = '!';
    }
}

void sub_d(int i_f,int j_f, char a[8][8] ) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i + j == i_f + j_f) {
                if (a[i][j] == 'F') {
                    continue;
                }
                a[i][j] = '!';
            }
        }
    }
}

void pseudo_main_d(int i_f,int j_f, char a[8][8] ) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i_f - i == j_f - j) {
                if (a[i][j] == 'F') {
                    continue;
                }
                a[i][j] = '!';
            }
        }
    }
}
int main() {
    int i_f = 0, j_f = 0;
    char chess_board[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> chess_board[i][j];
            if (chess_board[i][j] == 'F') {
                i_f = i;
                j_f = j;
            }
        }
    }
    row(i_f, chess_board);
    col(j_f, chess_board);
    sub_d(i_f, j_f, chess_board);
    pseudo_main_d(i_f, j_f, chess_board);
    for (auto & i : chess_board) {
        for (char j : i) {
            cout << j;
        }
        cout << endl;
    }
}