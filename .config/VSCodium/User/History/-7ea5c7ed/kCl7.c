#include <stdio.h>

int main(){
    int n; // addr1
    int *pn; // addr2
    int **ppn; //addr3
    int ***pppn; //addr4

    n = 42; 
    pn = &n; // pn = 0x7ffc93a515fc
    ppn = &pn; // ppn = 0x7ffcb204bf00
    pppn = &ppn; // pppn = addr3
    
    printf("%p == %p\n", **pppn, pppn);
}