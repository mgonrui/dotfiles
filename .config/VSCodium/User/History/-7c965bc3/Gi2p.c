#include <stdio.h>

int main (void){
    int checker_board[8][8];
    int col, row;
    int nrow = 1;
    char even, odd;
    for (col=0; col < 8; col++){
        for (row=0; row < 8; row++){
            if (nrow % 2 == 0){
                even = 'R';
                odd = 'B';
            }
            else {
                odd = 'R';
                even = 'B';
            }
            if (row % 2 == 0 ){
                checker_board[col][row] = even;
            }
            else {
                checker_board[col][row] = odd;
            }
        }
        nrow++;
        
    }
    for (col = 0; col < 8; col++){
        for (row = 0; row < 8; row++){
            printf("%c ", checker_board[col][row]);
        }
        printf("\n");
    }
    return 0;
}