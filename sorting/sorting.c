/*
 Program Name: sorting.c
 Author: Ankur Patel
 Program Intent: To analyze different type of sorts and print out the time it
                 takes to sort an array
 Compile Note: Compiling program using cc will give warnings but still compile
               the code
               Using gcc to compile will not give warnings and compile
               properly
               Code compiled in cc runs faster than code compiled in gcc
 */

/*---------------
 Include Section
 ----------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*--------------------
 Preprocessor Section
 ---------------------*/
#define MAX        32000
#define NUM_SORT   6


/*----------------------------  function ------------------------------------
 Name: cpy_array
 Purpose: Copy elements from one array to another array
 Pre: Both arrays must have size equal to or bigger than array_size
 Post: Copies all the elements from the first array to another starting
       from index 0 upto array_size-1 
 Arguments: arr is the array from which elements will be copied and to_arr is 
            the array to which the elements will be copied into. array_size is
            specifies how many elements need to be copied starting from first
            index
 Returns: void
 Calls: None
 ----------------------------------------------------------------------------*/
void cpy_array( int const arr[], int to_arr[], int array_size )
{
  int i;
  for( i = 0; i < array_size; i++ ) {
    to_arr[ i ] = arr[ i ];
  }
  
} 



/*----------------------------  function ------------------------------------
 Name: fill_array
 Purpose: To fill the array with random numbers
 Pre: arr must be of at least size array_size
 Post: Fills up the arr with random numbers
 Arguments: arr is the arr that will be filled with random numbers
            array_size is the size of the array to be filled with numbers
 Returns: void
 Calls: srand, rand
 ----------------------------------------------------------------------------*/
void fill_array( int arr[], int array_size )
{
  int i;
  srand( time(NULL) );
  
  for( i = 0; i < array_size; i++ ){
    arr[ i ] = rand();
  }

}




/*----------------------------  function ------------------------------------
 Name: bubble_sort
 Purpose: Sort given array using bubble sort algorithm
 Pre: Array a must be of atleast array_size
 Post: Sorts the array a 
 Arguments: a is the array that needs to be sorted and array_size is the size
            of the array
 Returns: void
 Calls: None
 Source: http://www.cs.princeton.edu/~ah/alg_anim/gawain-4.0/BubbleSort.html
 ----------------------------------------------------------------------------*/
void bubble_sort( int a[], int array_size )
{
  int i, j, tmp;

  for( i = 0; i < array_size; i++ ) {

    for( j = 0; j < ( array_size - 1 - i) ; j++) {

      if( a[ j + 1 ] < a[ j ] ) {  

        tmp = a[ j ]; 
        a[ j ] = a[ j + 1 ];
        a[ j + 1 ] = tmp;

      }//end if

    }//end for j

  }//end for i
  
}




/*----------------------------  function ------------------------------------
 Name: selection_sort
 Purpose: Sort given array using selection sort algorithm 
 Pre: Array must be of atleast array_size
 Post: Sorts the array upto array_size
 Arguments: numbers is the array that needs to be sorted and array_size is the
            index upto which the elements will be sorted
 Returns: void
 Calls: None
 Source: http://linux.wku.edu/~lamonml/algor/sort/selection.html
 ----------------------------------------------------------------------------*/
void selection_sort(int numbers[], int array_size)
{
  int i, j;
  int min, temp;
  
  for (i = 0; i < array_size-1; i++) {
    min = i;
    for (j = i+1; j < array_size; j++) {
      if ( numbers[ j ] < numbers[ min ] )
        min = j;
    }
    temp = numbers[ i ];
    numbers[ i ] = numbers[ min ];
    numbers[ min ] = temp;
  }
}




/*----------------------------  function ------------------------------------
 Name: shell_sort
 Purpose: Sort given array using shell sort algorithm
 Pre: numbers must be of atleast array_size
 Post: Sorts the array 
 Arguments: number is the array that needs to be sorted and array_size is the
            size of the array
 Returns: void
 Calls: None
 Source: http://linux.wku.edu/~lamonml/algor/sort/shell.html
 ----------------------------------------------------------------------------*/
void shell_sort(int numbers[], int array_size)
{
  int i, j, increment, temp;
  
  increment = 3;
  while (increment > 0) {
    for (i=0; i < array_size; i++) {
      j = i;
      temp = numbers[i];
      while ((j >= increment) && (numbers[j-increment] > temp)) {
        numbers[j] = numbers[j - increment];
        j = j - increment;
      }
      numbers[j] = temp;
    }
    if (increment/2 != 0)
      increment = increment/2;
    else if (increment == 1)
      increment = 0;
    else
      increment = 1;
  }

}





/*----------------------------  function ------------------------------------
 Name: insertion_sort
 Purpose: Sort given array using Insertion sort algorithm
 Pre: numbers must be atleast of array_size
 Post: Sorts the array
 Arguments: numbers is the array that needs to be sorted and array_size is the
            size of the array
 Returns: void
 Calls: None
 Source: http://linux.wku.edu/~lamonml/algor/sort/insertion.html
 ----------------------------------------------------------------------------*/
void insertion_sort(int numbers[], int array_size)
{
  int i, j, index;
        
  for (i=1; i < array_size; i++) {
    index = numbers[i];
    j = i;
    while ((j > 0) && (numbers[j-1] > index)) {
      numbers[j] = numbers[j-1];
      j = j - 1;
    }
    numbers[j] = index;
  }

}




/*----------------------------  function ------------------------------------
 Name: q_sort
 Purpose: Sort array using quick sort algorithm
 Pre: left must be less than right
 Post: Breaks the array into half and calls sort function again recursively
 Arguments: number is the array and left and right are the index up to which
            array needs to be sorted
 Returns: void
 Calls: q_sort
 Source: http://linux.wku.edu/~lamonml/algor/sort/quick.html
 ----------------------------------------------------------------------------*/
void q_sort(int numbers[], int left, int right)
{
  int pivot, l_hold, r_hold;
  
  l_hold = left;
  r_hold = right;
  pivot = numbers[left];
  while (left < right) {
    while ((numbers[right] >= pivot) && (left < right))
      right--;
    if (left != right) {
      numbers[left] = numbers[right];
      left++;
    }
    while ((numbers[left] <= pivot) && (left < right))
      left++;
    if (left != right) {
      numbers[right] = numbers[left];
      right--;
    }
  }
  numbers[left] = pivot;
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot)
    q_sort(numbers, left, pivot-1);
  if (right > pivot)
    q_sort(numbers, pivot+1, right);
}


/*----------------------------  function ------------------------------------
 Name: quick_sort
 Purpose: To call the recursive q_sort method
 Pre: numbers must be of atleast array_size
 Post: Calls the q_sort method to sort the array
 Arguments: number is the array that needs to be sorted and array_size is the
            array size
 Returns: void
 Calls: q_sort
 ----------------------------------------------------------------------------*/
void quick_sort(int numbers[], int array_size)
{
  q_sort(numbers, 0, array_size - 1);
}




/*----------------------------  function ------------------------------------
 Name: compare
 Purpose: Compares two elements
 Pre: None
 Post: Determines which element has greater value
 Arguments: m and n are pointers to elements that need to be compared
 Returns: int value of 0 if they are same, -1 if a < b or 1 if a > b
 Calls: None
 Source: Prof Kazemian
 ----------------------------------------------------------------------------*/
int compare(const void *m, const void *n)
{
  int *a, *b;
  a = (int *)m;
  b = (int *)n;
  if (*a < *b)
    return -1;
  if (*a == *b)
    return 0;
  if (*a > *b)
    return 1;
}


/*----------------------------  function ------------------------------------
 Name: stdlib_qsort
 Purpose: Call the qsort in the standard library
 Pre: Given array must be of atleast array_size
 Post: Calls the qsort method found in stdlib.h to sort the array
 Arguments: numbers is the array that needs to be sorted and array_size is the
            size of the array
 Returns: void
 Calls: qsort
 ----------------------------------------------------------------------------*/
void stdlib_qsort( int numbers[], int array_size ) 
{
	
  qsort( numbers, array_size, sizeof( int ), &compare );

}



/*----------------------------  function ------------------------------------
 Name: execute_sort
 Purpose: Copyies the orignal unsorted array into another array called copy
          Then is records the current time and execute corresponding function
          passed in the parameters. Once sort is done it records the end time
          and figures out time spaned for the sort and prints out the details
 Pre: orig and copy array need to be of atleast array_size
 Post: Sorts the array using the function address passed in as parameters
       and prints out the details
 Arguments: orig array is the array that contains random elements
            copy is the array to which random elements will be copied into
            array_size is how many elements will be copied into the copy array
            sort_name is the name of the sort executing
            sort_function is the pointer to the function that will be executed
 Returns: void
 Calls: None
 ----------------------------------------------------------------------------*/
void execute_sort( int const orig[], int copy[], int array_size, 
                   char* sort_name, void (*sort_function)(int[], int) ) 
{
	
  cpy_array( orig, copy, array_size );//Copy original random array
  
  clock_t before = clock(); //start timer
  
  sort_function( copy, array_size ); //execute function;
  
  printf( "\n%s of %d items took %f seconds\n", sort_name, array_size, 
          (double)(clock() - before )/CLOCKS_PER_SEC );
  
}




/*--------------------------- main function ----------------------------------
 Purpose: Start the program
 Pre: None
 Post: Table of values of pythagorean triples
 Arguments: None
 Returns: EXIT_SUCCESS to signify succesful execution
 Calls: fill_array, execute_sort, selection_sort, quick_sort, shell_sort, 
        stdlib_qsort, insertion_sort, bubble_sort
 ----------------------------------------------------------------------------*/
int main( )
{
	
  int orig[ MAX ], copy[ MAX ], i;
  
  /* array that hold sorts that will be performed in sequential order */
  void *function[ NUM_SORT ] = { &selection_sort, &quick_sort, &shell_sort, 
                                 &stdlib_qsort, &insertion_sort, &bubble_sort };
  /* array that holds sort names respective to the sorts that will be 
     performed */
  char *sort_name[ NUM_SORT ] = { "Selection sort", "Quicksort", "Shellsort", 
                                  "Qsort", "Insertion sort", "Bubble sort" };
	
  fill_array( orig, MAX );
  
  /* sorts being executed */
  for( i = 0; i < NUM_SORT; i++ ) {
    execute_sort( orig, copy, MAX, sort_name[ i ], function[ i ] );	
  }
  printf( "\n" );
  
  return (EXIT_SUCCESS);
  
}

