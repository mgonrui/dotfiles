#include <stdio.h>

void find_two_largest(int a[], int n, int *largest, int *second_largest);

void find_two_largest(int a[], int n, int *largest, int *second_largest){
    *largest = a[0];
    *second_largest = a[0];
    for (int i = 0; i < n; i++){
        if (i > *largest){
            *second_largest = *largest;
            *largest = i;
        }
    }
}

int main (void){
    int ar[] = {1, 5, 3, 6, 2};
    int fir, sec;
    find_two_largest(ar, 5, &fir, &sec);
    printf("largest %d", fir);
    printf("second_largest %d", sec);
    return 0;
}