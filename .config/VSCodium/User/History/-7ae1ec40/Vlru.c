#include <stdio.h>

int day_of_year(month, day, year){
    int nday;
    int months[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i< month; i++){
        nday += months[i];
    }
    return nday;
}