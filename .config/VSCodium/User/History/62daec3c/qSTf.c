#include <stdio.h>

int main (void){
    int ndays,
        startweek;
    printf("enter the number of days in month: ");
    scanf ("%d", &ndays);
    printf("enter starting day of the week (1=Sun, 7=Sat): ");
    scanf ("%d", &startweek);
    for (int i = 0; i <= ndays; ){
        for (int j = 0; j <= 7; j++){
            printf("%4d", i);
            if (i < ndays){
                i++;
            }
            else {
                break;
            }
        }
        printf("\n");
    }
    // printf("%20d",ndays);
    return 0;
}