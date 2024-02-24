#include <stdio.h>

void selection_sort(int arr[], int n);

int arint[10] = {};
int position = 0;
int num;

int main(void){
    printf("enter a series of intergers: ");
    while (getchar() != '\n'){
        scanf("%d", &num);
        arint[position] = num;
        position++;
    }
    selection_sort(arint, position);
    for (int i = 0; i < sizeof(arint) / sizeof(arint[0]) ; i++){
        printf("%d", arint[i]);
    }
    return 0;
}

void selection_sort(int arr[], int n){
    // printf("%d\n", n);
    int largest = arr[0];
    int old_position;
    int i;
    for (i = 0; i < n ; i++){
        if (arr[i] > largest){
            largest = arr[i];
            arr[i]  = arr[n];
        }
    }

    // printf("%d\n", arr[n]);
    // arr[n] = largest;
    // printf("%d\n", arr[n]);
    if (n > 0){
        n -=  1;
        selection_sort(arr, n);
    }

}