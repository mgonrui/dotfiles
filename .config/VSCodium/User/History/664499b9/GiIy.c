#include <stdio.h>

int main(void){
    int nrow,
        ncol,
        grid[5][5];
    for (nrow = 0 ; nrow < 5; nrow++){
        printf(" enter row %d: ", (nrow +1));
        scanf("%d %d %d %d %d ", &grid[nrow][ncol]);
        for (int i = 0; i < 5; i++){
            printf("%d ", grid[nrow][ncol]);
        }
        }
    }
    return 0;
}