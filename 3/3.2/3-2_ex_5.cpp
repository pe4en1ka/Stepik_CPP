#include <iostream>
using namespace std;

int main() {
    char chess_board[8][8];
    short int i_k = 0, j_k = 0;
    for (short int i = 0; i < 8; i++) {
        for (short int j = 0; j < 8; j++) {
            cin >> chess_board[i][j];
            if (chess_board[i][j] == 'K') {
                i_k = i;
                j_k = j;
            }
        }
    }
    if (i_k - 1 >= 0) {
        if (j_k - 2 >= 0) {
            chess_board[i_k - 1][j_k - 2] = '!';
        }
        if (j_k + 2 < 8) {
            chess_board[i_k - 1][j_k + 2] = '!';
        }
    }
    if (j_k - 1 >= 0) {
        if (i_k - 2 >= 0) {
            chess_board[i_k - 2][j_k - 1] = '!';
        }
        if (i_k + 2 < 8) {
            chess_board[i_k + 2][j_k - 1] = '!';
        }
    }
    if (i_k + 1 < 8) {
        if (j_k + 2 < 8) {
            chess_board[i_k + 1][j_k + 2] = '!';
        }
        if (j_k - 2 >= 0) {
            chess_board[i_k + 1][j_k - 2] = '!';
        }
    }
    if (j_k + 1 < 8) {
        if (i_k - 2 >= 0) {
            chess_board[i_k - 2][j_k + 1] = '!';
        }
        if (i_k + 2 < 8) {
            chess_board[i_k + 2][j_k + 1] = '!';
        }
    }
    for (auto & i : chess_board) {
        for (char j : i) {
            cout << j;
        }
        cout << endl;
    }
}