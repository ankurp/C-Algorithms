/*
 Program Name: jump.c
 Author: Ankur Patel
 Program Intent: To demonstrate longjmp and use of it as a try catch
 */

#include <setjmp.h>
#include <stdio.h>

int main() 
{

  jmp_buf buf;

  if (!setjmp(buf)) {
    printf("Raising Exception\n");
    printf("%lu\n%lu", sizeof(jmp_buf), sizeof(int));
    longjmp(buf, 1);
  } else {
    printf("Caught Exception\n");
  }

}
