 
/*
Program Name: palin.c
Author: Ankur Patel
Program Intent: To determine whether an input phrase or sentence or word is a
                palindrome
Input Data:     Sentence, phrase or word
Output Data:    Tells whether the input sentence, phrase or word is palindrome
*/

/*---------------
Include Section
----------------*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

/*--------------------
Preprocessor Section
---------------------*/



/*----------------------------  function ------------------------------------
Name: is_palindrome
Purpose: To determine whether the input string of words is a palindrome
Pre: Input must be array of characters and start and end index must be positive
Post: Determines whether the string is palindrome
Arguments: words array that contains a phrase or sentence or a word
           start index and end index of string whose characters will be compared
Returns: boolean value of true if input is palindrom, false if input is not
         palindrome
Calls: is_palindrome
----------------------------------------------------------------------------*/
bool is_palindrome( char word[], int start, int end )
{

  /* base condition where the characters are same */
  if( start >= end ){
    return true;

  }else if( word[start] == word[end] ){
    return is_palindrome( word, start + 1, end - 1);

  }else{
    return false;

  }
  
}


/*----------------------------  function ------------------------------------
Name: parse_string
Purpose: To remove non alphabetical characters from the input string
Pre: Input must be string
Post: Removes non alphabetical characters from the input string
Arguments: words that is a sentence, phrase or word
Returns: void
Calls: None
----------------------------------------------------------------------------*/
void parse_string( char words[] )
{

  int i, j = 0;

  for( i = 0; i < strlen( words ); i++ ) {
    
    if( isalpha( words[ i ] ) ) {
      words[ j ] = tolower( words[ i ] );
      j++;
    }

  }
  words[ j ] = '\0';

}


/*--------------------------- main function ----------------------------------
Purpose: Start the program
Pre: -
Post: Table of values of pythagorean triples
Arguments: -
Returns: 
Calls: is_palindrome, parse_string
----------------------------------------------------------------------------*/
int main( int argc, char** argv )
{
  
  char word[81];

  for( printf("\nEnter a string: "); strcmp( gets( word ), "done" ) != 0; 
       printf("Enter a string: ") ) {

    parse_string( word );
    
    is_palindrome( word, 0, strlen( word ) - 1 ) ?
      printf("\nIt is a palindrome\n\n") : 
      printf("\nIt is not a palindrome\n\n");

  }

  return (EXIT_SUCCESS);
  
}


 
