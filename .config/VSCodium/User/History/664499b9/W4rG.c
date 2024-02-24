#include <stdio.h>

int main(void){
    int nrow,
        ncol,
        grid[5][5];
    for (nrow = 0 ; nrow < 5; nrow++){
        printf(" enter row %d: ", (nrow +1));
        scanf("%d %d %d %d %d",&grid[nrow][0], &grid[nrow][1] ,&grid[nrow][2], &grid[3][ncol], &grid[4][ncol]);
        for (int i = 0; i < 5; i++){
            printf("%d ", grid[nrow][4]);
        }
        }
    return 0;
}