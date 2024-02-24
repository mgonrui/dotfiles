#include <stdio.h>

int main(void){
    int nrow,
        ncol,
        i,
        j,
        k,
        row_totals[5] = {0},
        column_totals[5] = {0},
        average_grade[5] = {0},
        average_quiz_score[5] = {0},
        high_quiz_score[5] = {0},
        low_quiz_score[5] = {0},
        grid[5][5];
    for (nrow = 0 ; nrow < 5; nrow++){
        printf(" enter notes of student n%d: ", (nrow +1));
        scanf("%d %d %d %d %d",&grid[nrow][0], &grid[nrow][1] ,&grid[nrow][2], &grid[nrow][3], &grid[nrow][4]);
        i = 0;
        }
    for ( j = 0; j < 5; j++){
        for ( k = 0; k < 5; k++){
            row_totals[j] += grid[j][k]; 
            column_totals[j] += grid[k][j]; 
            }
            k = 0;
    }
    
    for (k = 0; k < 5; k++){
        average_grade[k] = row_totals[k] / (sizeof(row_totals) / sizeof(row_totals[0]));
        average_quiz_score[k] = column_totals[k] / (sizeof(column_totals) / sizeof(column_totals[0]));
        high_quiz_score[k] = 0;
        low_quiz_score[k] = 0;
        for (j = 0; j < 5; j++){
            if (high_quiz_score[k] < grid[k][j]){
                high_quiz_score[k] = grid[k][j];
            }
            if (low_quiz_score[k] > grid[k][j]){
                low_quiz_score[k] = grid[k][j];
            }
        }
    }

        // printf("row  totals: %d %d %d %d %d\n", row_totals[0], row_totals[1],row_totals[2],row_totals[3],row_totals[4]);
        // printf("column totals: %d %d %d %d %d\n", column_totals[0], column_totals[1],column_totals[2],column_totals[3],column_totals[4]);
    return 0;
}