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
            if (row % 2 == 0 )
        }
        
    }
    return 0;
}