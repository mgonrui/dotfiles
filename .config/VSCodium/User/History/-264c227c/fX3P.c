
#include <stdbool.h>   /* C99 only */
#include <stdio.h>

int main(void)
{
  bool digit_seen[10] = {false};
  int digit;
  long n;
  int numbercount;
  int counter = 0;
  long list_of_numbers[]= {};
  char character;

  printf("Enter a number: ");
  while ((character = getchar()) != '\n') {
    if  (character == ' '){
      numbercount++;
    }
  }
printf("%d", numbercount);

//   while(1){
//     scanf("%ld", &n);
//     if (n <= 0 ){
//       break;
//     }
//     else {
//       list_of_numbers[counter] = n;
//     }
//     counter++;
//   }

// //   while (n > 0) {
// //     digit = n % 10;
// //     if (digit_seen[digit])
// //       break;
// //     digit_seen[digit] = true;
// //     n /= 10;
// //   }

// //   if (n > 0)
// //     printf("Repeated digit\n");
// //   else
// //     printf("No repeated digit\n");

  return 0;
}
