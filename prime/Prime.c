/*
Program Name: fact.c
Author: Ankur Patel
Program Intent: To print out the table of values of actual factorial values for
				given input. If input is positive except 0 and is less than or 
				equal to 12 then it print out the factorial along with the 
				Stirlings approximations from 1 to input value. If value is
				greater than 12 then it prints out only Stirling approximation
				from 1 to input value with interval of 5. Output is in table
				format.
Input Data: All positive integers except 0
Output Data: Table of value of actual factorial with Stirling approximations if
             input is less than or equal to 12 but positive. If input is greater
             than 12 then output is table of Stirling approximations.
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
Name: invalidInputError
Purpose: Prints invalid input error message
Pre: -
Post: Prints error message
Arguments: -
Returns: -
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
Name: invalidInputError
Purpose: Prints invalid input error message
Pre: -
Post: Prints error message
Arguments: -
Returns: -
Calls: -
----------------------------------------------------------------------------*/
void printPrimePairs( int max ) 
{
	int i;

	for( i = 2; i < max; i++ ){

		if( isPrime( i ) == TRUE )
			printf( "%8d is a prime\n", i );
			
	}

}

/*--------------------------- main function ----------------------------------
Purpose: Start the program
Pre: -
Post: Table of values of factorial upto given input
Arguments: -
Returns: 0 for success, otherwise failure
Calls: factorial, stirlingApproximation1, stirlingApproximation2, inputRequest,
		printHeaderWithFactorial, printApproximationHeader, printFactRow,
		printAppxRow
----------------------------------------------------------------------------*/
int main(  )
{
	int input;
	scanf( "%d", &input );
	
	printPrimePairs( input );
  
  return (EXIT_SUCCESS);
}


