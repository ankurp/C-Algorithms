/*
 Program Name: htoi.c
 Author: Ankur Patel
 Program Intent: To convert input hex number into integer
 */

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) 
{
  int sum = 0;
  int i;
  int j = 0;
  for (i = strlen(argv[argc-1]) - 1; i >= 0; i--) {
    sum += (argv[argc-1][j++]-'0') * pow(16, i);
  }

  printf("%d\n", sum);
}
