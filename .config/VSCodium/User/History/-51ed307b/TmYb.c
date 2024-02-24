#include <stdio.h>
// void find_two_largest(const int *a, int n, int *largest, int *second_largest){
//     *largest = *a;
//     *second_largest = *(a+1);
//     for ( int i = 0; i < n ; i++){
//         if (*largest < *(a+i)) {
//             *second_largest = *largest;
//             *largest = *(a+i);
//         }
//         else if (*second_largest < *(a+i)) {
//             *second_largest = *(a+i);
//         }
    
//     }
// }
void find_two_largest(const int *a, int n, int *largest, int *second_largest) {

    const int *p = a;
    *largest = *second_largest = *a;
    
    while (p++ < a + n) {
        if (*p > *largest) {
            *second_largest = *largest;
            *largest = *p;
        } else if (*p > *second_largest)
            *second_largest = *p;
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