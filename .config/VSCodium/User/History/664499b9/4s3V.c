#include <stdio.h>

int main(void){
    int nrow,
        ncol,
        grid[5][5];
    for (nrow = 0 ; nrow < 5; nrow++){
        printf(" enter row %d: ", (nrow +1));
        scanf("%d %d %d %d %d ", &grid[nrow][ncol]);
            printf("%d ", grid[nrow][nrow]);
        }
    }
    return 0;
}