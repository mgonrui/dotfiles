#include <stdio.h>

int main(){
    int n; // addr1
    int *pn; // addr2
    int **ppn; //addr3
    int ***pppn; //addr4

    n = 42; 
    pn = &n; // pn = addr1
    ppn = &pn; // ppn =  addr2
    pppn = &ppn; // pppn = addr3
    
    printf("%p == %p\n", *pppn, pn);
}