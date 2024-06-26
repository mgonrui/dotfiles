/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* square2.c (Chapter 6, page 110) */
/* Prints a table of squares using a for statement */

#include <stdio.h>

int main(void)
{
  int i, j, n;
  int ch;

  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in table: ");
  scanf("%d", &n);
  getchar();

  for (i = 1; i <= n; i++){
    for (j = 1; i <=24 ; j++, i++){
      printf("%10d%10d\n", i, i * i);
    }
    printf("press enter to continue... ");
    printf("\nj = %d\n", j);
    printf("i = %d\n", i);
    while (getchar() != '\n')
        ;
  }

  return 0;
}