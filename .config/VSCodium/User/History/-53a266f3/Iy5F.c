#include <stdio.h>

int *find_largest(int a[], int n);

int *find_largest(int a[], int n){
    int *largest = &a[0];
    for (int i = 0; i < n; i++){
        if (i > *largest){
            largest = &a[i];
        }
    }
    return largest;
}

int main (void){
    int array[] = {1, 3, 5, 4, 2};
    int len = 5;
    find_largest(array, len);
    printf("pointer: %p\n", find_largest(array, len));
    printf("value: %d\n", *find_largest(array, len));
    return 0;
}