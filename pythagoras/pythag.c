/*
Program Name: pythag.c
Author: Ankur Patel
data-code-language="c"Program Intent: Print out a table of value of pythagorean triples upto given
                input value. Pythagorean triples are realtively prime.
                Ex of Pythagorean triples are 3,4,5       5,12,13 and so on.
Input Data:     Positive integer
Output Data:    Table of pythagorean triples upto given input value.
*/

/*---------------
Include Section
----------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



/*----------------------------  function ------------------------------------
Name: gcd
Purpose: Get the gcd of two integers
Pre: Input must be positive
Post: Return the gcd of two integers recussively
Arguments: i and j are integers whose gcd is determines recursively
Returns: gcd of i and j
Calls: -
----------------------------------------------------------------------------*/
int gcd( int i, int j )
{

  if( j == 0 ) 
    return i;
  else
    return gcd( j, i % j );
  
}



/*----------------------------  function ------------------------------------
Name: get_hypotenuse
Purpose: To determine the hypotenuse given two side lengths
Pre: Input must be positive integers
Post: Returns the hypotenuse if hypotenuse is an integer else returns a zero
Arguments: a and b are length of the two sides of a right triangle
Returns: hypnotenuse if it is an integer else return 0
Calls: -
----------------------------------------------------------------------------*/
int get_hypotenuse( int a, int b )
{
  
  double hyp = sqrt( pow( a, 2 ) + pow( b, 2 ) );
  
  if( ceil( hyp ) == floor( hyp ) )
    return (int)hyp;
  else
    return 0;
  
}



/*----------------------------  function ------------------------------------
Name: generate_triple
Purpose: Creates the table of pythagorean triples upto max input value
Pre: Input must be positive integer
Post: Generate table of pythagorean triples
Arguments: max is the maximum value upto which pythagorean triples will be
           determined
Returns: void
Calls: get_hypotenuse, gcd
----------------------------------------------------------------------------*/
void generate_triple( int max )
{
  int i, j;

  for( i = 1; i < max; i++ ) {
    
    for( j = 1; j < i; j++ ) {
      
      if( gcd( i, j ) == 1 ) {
	
        int hyp = get_hypotenuse( i, j );
	
        if( hyp ) {
          printf( "%4d %4d %4d\n", j, i, hyp );
          break;
        }

      }//end if gcd
      
    }//end for index j
    
  }//end for index i
  
  printf( "\n" );

}


/*--------------------------- main function ----------------------------------
Purpose: Start the program
Pre: There should be one argument. Argument must be positive integer.
Post: Table of values of pythagorean triples
Arguments: -
Returns: EXIT_SUCCESS
Calls: generate_triple
----------------------------------------------------------------------------*/
int main( int argc, char** argv )
{
  
  if( argc == 2 ) {
    
    printf( "\n Pythagorean Triples\n" );
    printf( "=====================\n" );
    generate_triple( atoi( argv[ 1 ] ) );
    
  } else {
    printf( "\nMissing argument\n\n" );
    printf( "The command line should be: a.out <an integer>\n\n" );
  }
  
  return (EXIT_SUCCESS);
  
}


 
