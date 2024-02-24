#include <stdio.h>
void find_two_largest(const int *a, int n, int *largest, int *second_largest){
    *largest = *a;
    *second_largest = *(a+1);
    for ( int i = 0; i < n ; i++){
        if (*largest < *(a+i)) {
            *second_largest = *largest;
            *largest = *(a+i);
        }
    
    }
}

int main (void){
    int largest = 0, second_largest = 0;
    int a[5] = {9, 2, 4, 5, 3};
    find_two_largest(a, 5, &largest, &second_largest);
    printf("largest: %d\n", largest);
    printf("second_largest: %d\n", second_largest);
    return 0;
}