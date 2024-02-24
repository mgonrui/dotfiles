#include <unistd.h>

void ft_print_comb(void){
    int n1,
        n2,
        n3;

        n1 = '0';
        n2 = n1 +1;
        n3 = n1 +2;
        write(1, &n1, 1);
        write(1, &n2, 1);
        write(1, &n3, 1);
}

int main(void){
    ft_print_comb();
}