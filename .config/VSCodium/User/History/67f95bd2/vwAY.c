#include <stdio.h>

void selection_sort(int arr[], int n);

int arint[100] = {};
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
    for (int i = 0; i < n ; i++){
        if (arr[i] > largest){
            largest = arr[i];
        }
    }
    arr[n] = largest;
    if (n > 0){
        n -=  1;
        selection_sort(arr, n);
    }

}