#include <stdio.h>

int main (void) {
    char chess_board[8][8] = {
        [0] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        [2] = {' ', '.', ' ', ' ', '.', ' ', '.', ' '},
        [3] = {'.', ' ', '.', '.', ' ', '.', ' ', '.'},
        };
    for (int i = 0; i < 8; i++){
        chess_board[1][i] = 'p' ;
        chess_board[5][i] = chess_board[3][i];
        chess_board[4][i] = chess_board[2][i];
        chess_board[6][i] = 'P';
        chess_board[7][i] = chess_board[0][i] - 32; 
    }
    for (int i = 0; i < 8; i++){
        printf("%c", chess_board[0][i]);
    }
    return 0;
}