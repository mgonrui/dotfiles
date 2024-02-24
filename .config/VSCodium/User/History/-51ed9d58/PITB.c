#include <stdbool.h>
#include <stdio.h>
#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int *top_ptr = 0;

int main (void){
    printf("%d\n", *top_ptr);
}

// void make_empty(void)
// {
//     top = 0;
// }
// bool is_empty(void)
// {
//     return top == 0;
// }
// bool is_full(void)
// {
//     return top == STACK_SIZE;
// }
// void push(int i)
// {
//     if (is_full())
//         stack_overflow();
//     else
//         contents[top++] = i;
// }
// int pop(void)
// {
//     if (is_empty())
//         stack_underflow();
//     else
//         return contents[--top];
// }