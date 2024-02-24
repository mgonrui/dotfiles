#include <stdio.h>

int main(){
    int n; // addr1
    int *pn; 
    int **ppn; 
    int ***pppn; 

    n = 42; 
    pn = &n; // pn = addr1
    ppn = &pn; // ppn =  addr2
    pppn = &ppn; // pppn = addr3
    
    printf("%p == %p\n", pn, pn);
}