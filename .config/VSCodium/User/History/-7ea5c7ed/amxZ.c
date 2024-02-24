#include <stdio.h>

int swap (int n, int n1){
    int tmp;
    tmp = n;
    n = n1;
    n1 = tmp;
    return n ;
}

int main(){
    int a;
    int b;
    a = 42;
    b = 1337;
    printf("a equal to %d \tb equal to %d\n", a, b);
    swap(a, b);
    printf("a equal to %d \tb equal to %d\n", a, b);
}