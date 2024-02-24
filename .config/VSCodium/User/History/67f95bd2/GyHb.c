#include <stdio.h>

void selection_sort(int arr[], int n);

int arint[] = {};
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
    return 0;
}

void selection_sort(int arr[], int n){
    int largest = arr[0];
    for (int i = 0; i < n; i++){
        if (arr[i] > largest){
            printf("hello");
            // largest = arint[i];
        }
    }
    // arint[n] = largest;
    // n -=  1;
    // selection_sort(arr, n);

}