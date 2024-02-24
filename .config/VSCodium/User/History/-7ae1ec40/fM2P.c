#include <stdio.h>

int day_of_year(month, day, year){
    int nday;
    int months[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i< month; i++){
        nday += months[i];
    }
    nday += day;
    return nday;
}

int main(void){
    printf("%d", day_of_year(01,29, 2018));
    return 0;
}