/*
 Program Name: postfix.c
 Program Intent: To tell whether input is valid postfix syntax
 */

#include <ctype.h>
int lookahead;

main() 
{
  lookahead = getchar();
  expr();
  putchar('\n');
}

expr() 
{
  term();
  while( 1 )
    if( lookahead == '+' ) {
      match( '+' ); term(); putchar( '+' );
    } else if( lookahead == '-' ) {
      match( '-' ); term(); putchar( '-' );
    } else {
      break;
    }
}

term() 
{
  if( isdigit( lookahead ) ) {
    putchar( lookahead );
    match( lookahead );
  } else {
    error();
  }
}

match( t )
int t;
{
  if( lookahead == t ) {
    lookahead = getchar();
  } else {
    error();
  }
}

error() 
{
  printf( "Syntax error\n" );
  exit( 1 );
}
