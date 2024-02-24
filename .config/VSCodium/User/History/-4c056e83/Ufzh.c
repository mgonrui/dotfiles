#include <unistd.h>

void ft_print_comb2(void){
    int first_pair,
        second_pair;


    while( first_pair <= 98){
        second_pair = first_pair +1;
        while ( second_pair <= 99 ){
            write(1, &first_pair, 1);
            write(1, &second_pair, 1);
            second_pair++;
        }
        first_pair++;
    }
}