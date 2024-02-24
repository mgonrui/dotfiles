#include <stdio.h>

void find_two_largest(int a[], int n, int *largest, int *second_largest);

void find_two_largest(int a[], int n, int *largest, int *second_largest){
    *largest = a[0];
    *second_largest = a[0];
    for (int i = 0; i < n; i++){
        if (a[i] > *largest){
            *largest= a[i];
        }
        if (*largest == *second_largest){
            *second_largest = a[1];
        }
        if (a[i] >= *second_largest && a[i] < *largest){
            *second_largest = a[i];
        }
    }
}

int main (void){
    int ar[] = {199, 1000, 3, 6, 2};
    int fir, sec;
    find_two_largest(ar, 5, &fir, &sec);
    printf("largest %d\n", fir);
    printf("second_largest %d", sec);
    return 0;
}