#include <stdio.h>

int main (void){
    int ndays,
        startweek;
    printf("enter the number of days in month: ");
    scanf ("%d", &ndays);
    printf("enter starting day of the week (1=Sun, 7=Sat): ");
    scanf ("%d", &startweek);
    for (int i; i <= startweek; i++){
    }
    printf("%20d",ndays);
    return 0;
}