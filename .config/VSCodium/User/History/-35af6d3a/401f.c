/* repdigit.c (Chapter 8, page 166) */
/* Checks numbers for repeated digits */

#include <stdbool.h>   /* C99 only */
#include <stdio.h>

int main(void)
{
  bool digit_seen[10] = {false};
  int digit_repeated[10] = {0};
  int digit;
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

  while (n > 0) {
    digit = n % 10;
    if (digit_seen[digit]){
      digit_repeated[digit] += 1 ;
    }
    digit_seen[digit] = true;
    n /= 10;
  }

  for (int i=0; i < sizeof(digit_seen) / sizeof(digit_seen[0]); i++){
    if (digit_repeated[i] > 0){
      printf("the following digit was repeaded %d times : %d  \n", digit_repeated[i]  + 1 ,  i);
    }
  }

  // if (n > 0)
  //   printf("Repeated digit\n");
  // else
  //   printf("No repeated digit\n");

  return 0;
}
