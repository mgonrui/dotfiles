#include <stdio.h>

int main(){
    int n; // addr 1
    int *pn;
    int **ppn;
    int ***pppn;

    n = 42; 
    pn = &n;
    ppn = &pn;
    pppn = &ppn;
    
    printf("%p == %p\n", *pppn, ppn);
}