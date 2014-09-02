
/*
 Program Name: matrix.c
 Author: Ankur Patel
 Program Intent: To multiply two matrices if operation is legal
 Input Data: Data is read from file where the first line contains the size of
             the matrix (row column) and data the way it is stored in a matrix
             sepearated by space. Data is read from two files whose name is
             specified in the argument
 Output Data: Prints out both matrices and print the multiplication of the 
              matrices
 */

/*---------------
 Include Section
 ----------------*/
#include <stdio.h>
#include <stdlib.h>


/*----------------------
Structure Declarations
-----------------------*/
struct  {
  int **matrix;
  int row;
  int column;
}typedef MATRIX;


/*-------------------
Function Prototypes
--------------------*/
void print_matrices( MATRIX *m1, MATRIX *m2, MATRIX *result );
MATRIX *multiply_matrix( MATRIX *m1, MATRIX *m2 );
MATRIX *create_matrix( FILE *stream );



/*----------------------------  function ------------------------------------
 Name: multiply_matrix
 Purpose: To multiply two matrices and store the result in dynamically allocated
          memory
 Pre: m1 and m2 must have row and column data item initialized in the MATRIX
      structure
 Post: Multiplies two matrices and stores it in a dynamically allocated memory
 Arguments: m1 and m2 are matrices that need to be multiplied
 Returns: A pointer to the MATRIX structure that is the result of the 
          multiplication
 Calls: malloc, calloc
 ----------------------------------------------------------------------------*/
MATRIX *multiply_matrix( MATRIX *m1, MATRIX *m2 )
{

  int i, j, m;

  /* Allocate memory for MATRIX structure */
  MATRIX *result = (MATRIX *)malloc( sizeof( MATRIX ) );
  
  /* Dynamically allocate 2D array and initialize its row and count*/
  result->matrix = (int**)calloc( m1->row, sizeof( int* ) );

  for( i = 0; i < m2->column; i++ ) {
    (result->matrix)[ i ] = (int*)calloc( m2->column, sizeof( int ) );	
  }
  result->row = m1->row;
  result->column = m2->column;
  

  /* Perform multiplication algorithm */
  for( m = 0; m < m1->row; m++ ) {
    for( i = 0; i < m2->column; i++ ) {
      for( j = 0; j < m2->row; j++ ) {

        (result->matrix)[ m ][ i ] += ( m1->matrix )[ m ][ j ] * 
                                      ( m2->matrix )[ j ][ i ];

      }
    }
  }
  
  return result;
  
}



/*----------------------------  function ------------------------------------
 Name: create_matrix
 Purpose: To create dynamically allocated matrix using data from the input
          stream
 Pre: stream must not be null
 Post: Creates a matrix using the data read from input stream
 Arguments: stream is the opened stream to a file
 Returns: A pointer to the matrix structure that is dynamically allocated
 Calls: malloc, calloc
 ----------------------------------------------------------------------------*/
MATRIX *create_matrix( FILE *stream )
{
  int rows, columns, i, j;
  
  fscanf( stream, "%d", &rows );
  fscanf( stream, "%d", &columns );
  
  /* Dynamically create 2D array and add data to it from input stream */
  int **matrix = (int**)calloc( rows, sizeof( int* ) );

  for( i = 0; i < rows; i++ ) {

    matrix[ i ] = (int*)calloc( columns, sizeof( int ) );

    for( j = 0; j < columns; j++ ) {
      fscanf( stream, "%d", &(matrix[ i ][ j ]) );
    }
    
  }
  
  MATRIX *m = (MATRIX *)malloc( sizeof( MATRIX ) );
  m->matrix = matrix;
  m->row = rows;
  m->column = columns;
  
  return m;
}



/*----------------------------  function ------------------------------------
 Name: print_matrices
 Purpose: Print the data in the matrices. It prints the first, the second
          and the resulting matrices as specified
 Pre: All matrices in the argument must have row and column data item 
      initialized in the MATRIX structure
 Post: Prints out the data in the matricies
 Arguments: m1, m2 and result are matrices that will be printed on the screen
 Returns: void
 Calls: None
 ----------------------------------------------------------------------------*/
void print_matrices( MATRIX *m1, MATRIX *m2, MATRIX *result )
{
	
  int i, j;
  
  printf("\nThe matrices are:\n\n");
  for( i = 0; i < m1->row; i++ ) {
    for( j = 0; j < m1->column; j++ ) {
      printf( "%4d", (m1->matrix)[ i ][ j ] );
    }
    printf("\n");
  }
  printf("\nAnd\n\n");
  for( i = 0; i < m2->row; i++ ) {
    for( j = 0; j < m2->column; j++ ) {
      printf( "%4d", (m2->matrix)[ i ][ j ] );
    }
    printf("\n");
  }
  printf("\nTheir product is:\n\n");
  for( i = 0; i < result->row; i++ ) {
    for( j = 0; j < result->column; j++ ) {
      printf( "%4d", (result->matrix)[ i ][ j ] );
    }
    printf("\n\n");
  }
  
}



/*--------------------------- main function ----------------------------------
 Purpose: Start the program
 Pre: Argument count must be 3 and the last two arguments must be filename
      from which data will be read and converted to matrix
 Post: Reads from file and creates a matrix. Then it multiplies them if it is 
       legal and prints the result. Otherwise print error messages depending on
       type of error.
 Arguments: Arguments should contain two file names. Both from which matric data
            will be read.
 Returns: EXIT_SUCESS if execution was successful otherwise -1 for error 
 Calls: create_matrix, multiply_matrix, print_matrices, free
 ----------------------------------------------------------------------------*/
int main( int argc, char **argv )
{
  
  if( argc != 3 ) { // If arguments count not corrent show error and exit

    printf( "\nMissing file name or file names\n" );
    printf( "The proper format is: a.out filename1 filename2\n\n" );

  } else { 
    
    FILE *in_file = fopen( argv[1], "r" );
    FILE *out_file = fopen( argv[2], "r" );
    
    if( !in_file ) {
      printf( "\n%s: No such file or directory\n\n", argv[ 1 ] );
      return -1;
    }
    
    if( !out_file ) {
      printf( "\n%s: No such file or directory\n\n", argv[ 2 ] );
      return -1;
    }
    
    /* Create matrix structures that hold matrix and its size information */
    MATRIX *m1 = create_matrix( in_file ), 
           *m2 = create_matrix( out_file ), *result;
    

    if( m1->column == m2->row ) { // If matrix multiplication is legal do it
      
      result = multiply_matrix( m1, m2 );
      print_matrices( m1, m2, result );
      
      free( result );

      
    } else { //else print error

      printf( "\nMatrices are: %d x %d and %d x %d and " 
              "cannot be multiplied\n\n",
              m1->row, m1->column, m2->row, m2->column );

    }
    
    
    /*  Clean up */
    free( m1 );
    free( m2 );
    fclose( in_file );
    fclose( out_file );
		
  }
	
  return (EXIT_SUCCESS);
	
}
