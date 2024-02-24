#include <stdio.h>

int main(void){
    int nrow,
        ncol,
        i,
        row_totals[5],
        column_totals[5],
        grid[5][5];
    for (nrow = 0 ; nrow < 5; nrow++){
        printf(" enter row %d: ", (nrow +1));
        scanf("%d %d %d %d %d",&grid[nrow][0], &grid[nrow][1] ,&grid[nrow][2], &grid[nrow][3], &grid[nrow][4]);
        i = 0;
        }
    return 0;
}