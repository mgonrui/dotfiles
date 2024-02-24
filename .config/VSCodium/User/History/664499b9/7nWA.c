#include <stdio.h>

int main(void){
    int nrow,
        ncol,
        grid[5][5];
    for (nrow = 0 ; nrow < 5; nrow++){
        printf(" enter row %d", nrow -1);
        for (ncol= 0 ; ncol < 5; ncol++){
            scanf("%d ", &grid[nrow][nrow]);
            printf("%d ", grid[nrow][nrow]);
        }
    }
    return 0;
}