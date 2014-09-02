/*
Program Name: fact.c
Author: Ankur Patel
Program Intent: To print out the table of values of actual factorial values for
		given input. If input is positive except 0 and is less than for 
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
#define PI              3.141592653589793


/*----------------------------  function ------------------------------------
Name: factorial
Purpose: Calculates n!
Pre: n is positive excluding 0
Post: Returns positive number which is the factorial of the input
Arguments: Integer n whose factorial is calculated
Returns: If n is 0 or 1 then returns 1 otherwise returns (n-1)! * n
Calls: factorial
----------------------------------------------------------------------------*/
int factorial( int n )
{
  if( n == 1 || n == 0 ){
    return 1;
  } else {
    return factorial( n - 1 ) * n;
  }
  
}

/*----------------------------  function ------------------------------------
Name: stirlingsApproximation1
Purpose: Calculate approximation of n!
Pre: n is positive excluding 0
Post: Returns positive number which is the factorial of the input
Arguments: Integer n whose factorial is calculated
Returns: Approximation of n!
Calls: pow, sqrt, exp
----------------------------------------------------------------------------*/
double stirlingsApproximation1( int n )
{
  return pow( n, n ) * exp( -n ) * sqrt( 2.0 * PI * n );

}


/*----------------------------  function ------------------------------------
Name: stirlingApproximation2
Purpose: Calculate more accurate approximate value of n!
Pre: n is positive excluding 0
Post: Returns positive number which is the factorial of the input
Arguments: Integer n whose factorial is calculated
Returns: More accurate approximation of n!
Calls: pow, sqrt, exp
----------------------------------------------------------------------------*/
double stirlingsApproximation2( int n )
{
  return ( pow( n, n ) * exp( -n ) * sqrt( 2.0 * PI * n ) ) * 
    ( 1.0 + ( 1.0 / (double)( 12 * n ) ) );
}


/*----------------------------  function ------------------------------------
Name: printHeaderWithFactorial
Purpose: Print out the header for table with Factorial and both Stirling
		 Approximations
Pre: -
Post: Prints out the header for the table
Arguments: -
Returns: -
Calls: -
----------------------------------------------------------------------------*/
void printHeaderWithFactorial( )
{
  printf( "Number\tFactorial\tApproximation1\t\tApproximation2\n" );
  printf( "-------------------------------------------------------"
          "--------\n");
}


/*----------------------------  function ------------------------------------
Name: printApproximationHeader
Purpose: Print out the header for table with only Stirling Approximations
Pre: -
Post: Prints out the header for the table
Arguments: -
Returns: -
Calls: -
----------------------------------------------------------------------------*/
void printApproximationHeader( )
{
  printf( "Number\tApproximation1\t\tApproximation2\n" );
  printf( "------------------------------------------------------\n");
  
}


/*----------------------------  function ------------------------------------
Name: printFactRow
Purpose: Print row for table with actual factorial and Stirlings Approximation
Pre: -
Post: Prints a row
Arguments: print num i, factorial fact, and stirling approximation appx1 and
		   appx2
Returns: -
Calls: -
----------------------------------------------------------------------------*/
void printFactRow( int i, int fact, double appx1, double appx2 ){

  printf( "%4d\t%9d\t%12.6e\t\t%12.6e\n", i, fact, appx1, appx2 );

}


/*----------------------------  function ------------------------------------
Name: printAppxRow
Purpose: Print row for table with only Stirlings Approximation
Pre: -
Post: Prints a row
Arguments: print num i, and stirling approximation appx1 and
		   appx2
Returns: -
Calls: -
----------------------------------------------------------------------------*/
void printAppxRow( int i, double appx1, double appx2 ){

  printf( "%4d\t%12.6e\t\t%12.6e\n", i, appx1, appx2 );

}


/*----------------------------  function ------------------------------------
Name: inputRequest
Purpose: Print input request message
Pre: -
Post: Prints the message to prompt for input
Arguments: -
Returns: -
Calls: -
----------------------------------------------------------------------------*/
void inputRequest( ){
  printf( "\nPlease enter a nonnegative integer: " );
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
void invalidInputError( ){

  printf( "\nThe factorial is undefined for negative integers.\n" );
  
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

  inputRequest();

  for( scanf( "%d", &input ); input != 99999; scanf( "%d", &input ) ){

    if( input <= 0 ) {

      invalidInputError( );

    } else {

      int i;

      if( input <= 12 ){
        
        printHeaderWithFactorial();
        for( i = 1; i <= input; i++ ){
          printFactRow( i, factorial( i ), stirlingsApproximation1( i ), 
                    stirlingsApproximation2( i ) );

        }

      } else {

        
        printApproximationHeader();
        
        printAppxRow( 1, stirlingsApproximation1( 1 ), 
                      stirlingsApproximation2( 1 ) );
        
        for( i = 5; i < input; i+=5 ){
          printAppxRow( i, stirlingsApproximation1( i ), 
                        stirlingsApproximation2( i ) );
          
        }
        printAppxRow( input, stirlingsApproximation1( input ), 
                      stirlingsApproximation2( input ) );
        
      }
    }
    
    inputRequest();
    
  }
  
  return (EXIT_SUCCESS);
}


