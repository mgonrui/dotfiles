#include <stdio.h>

int day_of_year(month, day, year){
    int nday;
    int months[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i< month -1; i++){
        nday += months[i];
    }
    nday += day;
    return nday;
}

int main(void){
    printf("%d", day_of_year(03,01, 2018));
    return 0;
}