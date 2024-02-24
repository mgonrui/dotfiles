// #include <stdio.h>

// void selection_sort(int arr[], int n);

// int arint[5] = {};
// int position = 0;
// int num;

// int main(void){
//     printf("enter a series of intergers: ");
//     while (getchar() != '\n'){
//         scanf("%d", &num);
//         arint[position] = num;
//         position++;
//     }
//     selection_sort(arint, position);
//     for (int i = 0; i < sizeof(arint) / sizeof(arint[0]) ; i++){
//         printf("%d", arint[i]);
//     }
//     return 0;
// }

// void selection_sort(int arr[], int n){
//     // printf("%d\n", n);
//     int largest = arr[0];
//     int swap;
//     int i;
//     for (i = 0; i < n ; i++){
//         if (arr[i] > largest){
//             largest = arr[i];
//         }
//     }
//     swap = largest;
//     largest = arr[n - 1];
//     arr[n - 1] = swap;

//     // printf("%d\n", arr[n]);
//     // printf("%d\n", arr[n]);
//     if (n > 0){
//         n -=  1;
//         selection_sort(arr, n );
//     }

// }


#include <stdio.h>

#define MAX_LEN 100

void selection_sort(int a[], int n);

int main(void) {

    int i, c, n, a[MAX_LEN];
    printf("Enter list of integers to be sorted: ");
    for (i = 0, n = 0; i < MAX_LEN; i++) {
        scanf(" %d", &a[i]);
        n++;
        if ((c = getchar()) == '\n') /* ungetc() not yet covered,    */
            break;                   /* but used to put the non-'\n' */
        ungetc(c, stdin);            /* char back to be re-read.     */
    }

    selection_sort(a, n);
    
    printf("Sorted list:");
    for (i = 0; i < n; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");

    return 0;
}

void selection_sort(int a[], int n) {

    if (n == 0) return;

    int i, temp, largest = 0;

    for (i = 0; i < n; i++) {
        if (a[i] > a[largest])
            largest = i;
    }

    temp = a[largest];
    a[largest] = a[n-1];
    a[n-1] = temp;

    selection_sort(a, n-1);
}
