#include <stdio.h>

int main(){
    int n; // addr1
    int *pn; // addr2
    int **ppn; //addr3
    int ***pppn; //addr4

    n = 42; 
    pn = &n; // pn = addr 1
    ppn = &pn; // ppn = 
    pppn = &ppn;
    
    printf("%p == %p\n", **pppn, pn);
}