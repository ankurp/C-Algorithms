/*
Program Name: primepairs.c
Author: Ankur Patel
Program Intent: Prints out table of prime pairs up to input value. A prime pair 
                is two prime numbers that differ by 2. Ex 3 and 5 are prime
                pair.

Input Data: All positive integers less than 100000
Output Data: Table of value of prime pairs up to input value.
*/

/*---------------
Include Section
----------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*--------------------
Preprocessor Section
---------------------*/
#define	FALSE	0
#define	TRUE	1


/*----------------------------  function ------------------------------------
Name: isPrime
Purpose: To determine if an integer passed in is a prime number
Pre: Input number must be integer and postive
Post: Returns true if num is prime otherwise return false
Arguments: num which is an int type
Returns: Returns TRUE which is int value of 0 if num is prime otherwise returns
         FALSE which is int value of 1 
Calls: -
----------------------------------------------------------------------------*/
int isPrime( int num )
{
  int j;
  int isPrime = TRUE;
  
  for( j = 2; j <= ceil( sqrt( num ) ); j++ ) {

    if( (num % j) == 0 )
      isPrime = FALSE;

  }
  
  return isPrime;
}


/*----------------------------  function ------------------------------------
Name: printPrimePairs
Purpose: Prints out prime pairs
Pre: Input num should be positive
Post: Print table of prime pairs returning nothing
Arguments: max is the number upto which prime pairs need to be determined
Returns: void
Calls: isPrime
----------------------------------------------------------------------------*/
void printPrimePairs( int max ) 
{
  int i;
  
  for( i = 2; i < max - 2; i++ ){
    
    if( isPrime( i ) == TRUE && isPrime( i + 2 ) == TRUE )
      printf( "%6d %6d is a prime pair\n", i, i + 2 );
    
  }
  
}


/*--------------------------- main function ----------------------------------
Purpose: Start the program
Pre: -
Post: Table of values of prime pairs upto given input
Arguments: -
Returns: 0 for success, otherwise failure
Calls: printPrimePairs
----------------------------------------------------------------------------*/
int main(  )
{
  
  int input;

  printf( "\nEnter a positive integer <= 100000 and the program" );
  printf( "\nwill print all prime pairs upto that value: " );
  

  while( scanf( "%d", &input ) ){

    if( input < 0 || input > 100000 ) {

      printf( "\nThe integer must be positive and <= 100000\n" );
      printf( "Enter a positive integer <= 100000: " );
      continue;

    } else {

      printf( "\n" );
      printPrimePairs( input );
      printf( "\n" );
      break;

    }

  }
  
  return (EXIT_SUCCESS);

}


