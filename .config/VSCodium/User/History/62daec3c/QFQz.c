#include <stdio.h>

int main (void){
    int ndays,
        startweek;
    printf("enter the number of days in month: ");
    scanf ("%d", &ndays);
    printf("enter starting day of the week (1=Sun, 7=Sat): ");
    scanf ("%d", &startweek);
    for (int i = 0; i <= ndays; i++){
        for (int week = 0; week < (7 - startweek); week++){
            printf("%3d", i);
            i++;
        }
        printf("\n");
    }
    // printf("%20d",ndays);
    return 0;
}