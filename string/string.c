/*
Program Name: string.c
Author: Ankur Patel
Program Intent: To determine the count of each character in english alphabet
                in a given string and show the result in standard output
Input Data:     Sentence, phrase or word
Output Data:    Shows the occurance of each letter in english alphabet in
                given sentence, phrase or word
*/

/*---------------
Include Section
----------------*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

/*--------------------
Preprocessor Section
---------------------*/
#define DELTA              256
#define INIT_STRING_SIZE   80 //Initial string size
#define NUM_LETTERS        26 //Num letters in language


/*----------------------------  function ------------------------------------
Name: read_input
Purpose: Reads from standard input and creates a dynamically allocated array
         of characters where it places the input. Input is read upto a new line
Pre: Input must be series of characters followed by a new line for termination
Post: Saves the characters in a dynamically allocated array
Arguments: None
Returns: string of characters that was read from the input
Calls: malloc, realloc
----------------------------------------------------------------------------*/
char *read_input( )
{
  char in_char;
  int string_size =  INIT_STRING_SIZE * sizeof( char );
  int count = 0;
  char *string = (char*)malloc( string_size );


  assert( string != NULL ); //Check to see if memory is allocated

  
  for( in_char = getchar(); in_char != '\n' ; in_char = getchar() ) {
    
    if( count >= string_size ) {
      string_size += DELTA;
      string = realloc( string, string_size );

      assert( string != NULL ); // check to see if memory was reallocated

    }
    
    string[ count ] = in_char;
    count++;

  }
  string[count] = '\0';
  
  return string;
  
}


/*----------------------------  function ------------------------------------
Name: count_char
Purpose: To count the occurance of a character in a string
Pre: Input must be a string of characters
Post: Output is going to be an array that hold the count of each alphabetical
      character
Arguments: string of characters to be counted
Returns: array of count of alphabetical characters in string
Calls: isalpha, toupper, calloc
----------------------------------------------------------------------------*/
int *count_char( char *string  )
{
  int *count_array = (int*) calloc( NUM_LETTERS, sizeof(int) ), i;

  assert( count_array != NULL );
  
  for( i = 0; i < NUM_LETTERS; i++ ) {
    count_array[ i ] = 0;
  }
  
  for( i = 0; string[ i ] != '\0'; i++ ) {
    
    //Check to see if it is alphabet
    if( isalpha( string[ i ] ) ) {

      //convert the alphabet to uppercase and subtract char A to get
      //corresponding index and then increment the value at that index
      count_array[ toupper( string[ i ] ) - 'A' ]++;

    }
    
  }
  
  return count_array;

}


/*----------------------------  function ------------------------------------
Name: print_count
Purpose: To print out the occurance of alphabets in a string
Pre: Input must be an array of count of each alphabetical character
Post: Prints out the occurance of each alphabet if it occurs 1 or more times
Arguments: An array of count of alphabets
Returns: void
Calls: None
----------------------------------------------------------------------------*/
void print_count( int* count  )
{  
  int i;

  printf( "\n" );
  
  for( i = 0; i < NUM_LETTERS; i++ ) {
    
    if( count[ i ] > 0 ) {
      printf( "The number of %c 's = %d\n", (i + 97), count[ i ] );
    }
    
  }
  printf( "\n" );
  
}


/*--------------------------- main function ----------------------------------
Purpose: Start the program
Pre: -
Post: Table of values of pythagorean triples
Arguments: -
Returns: 
Calls: read_input, count_char, print_count
----------------------------------------------------------------------------*/
int main( int argc, char** argv )
{
  
  printf( "\nInput a string of any length: " );

  char* string = read_input();
  
  int* count = count_char( string );
  
  print_count( count );
  
  free( string );
  free( count );
  string = 0;
  count = 0;
  
  return (EXIT_SUCCESS);
  
}

