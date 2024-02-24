#include <stdio.h>

int main(){
    int n; // addr 1
    int *pn;
    int **ppn;
    int ***pppn;

    n = 42; 
    pn = &n; // pn = addr 1
    ppn = &pn; // ppn = 
    pppn = &ppn;
    
    printf("%p == %p\n", **pppn, ppn);
}