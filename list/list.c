/*
 Program Name: list.c
 Author: Ankur Patel
 Program Intent: To create a dynamic linked list of integers that can add and
                 delete node and keeps the list sorted in ascending order
 Input Data: Integers for standard input
 Output Data: Prints linked list after every insertion or deletion
 Compile Note: Use gcc to compile as cc does not recognize stdbool.h file
 */

/*---------------
 Include Section
 ----------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*--------------------
 Preprocessor Section
 ---------------------*/
#define MALLOC( type ) ( (type*) malloc( sizeof(type) ) )


/*----------------------
Structure Declarations
-----------------------*/
struct NODE {
  int data;
  struct NODE *next;
};

typedef struct {
  struct NODE *head;
  int size;
} List;



/*-------------------
Function Prototypes
--------------------*/
List *create_list();
void clean_up( List *list );
void insert( List *list, int value );
void delete( List *list, int value );
bool is_empty( List *list );
bool contains( List *list, int value );
void print_list( List *list );
void print_list_prompt( List *list );



/*----------------------------  function ------------------------------------
 Name: create_list
 Purpose: Creates a list structure and returns a pointer to it
 Pre: None
 Post: Creates and initializes the list
 Arguments: None
 Returns: Dynamically allocated list structure
 Calls: malloc
 ----------------------------------------------------------------------------*/
List *create_list()
{
  List *list = (List*)malloc( sizeof( List ) );
  list->size = 0;
  list->head = 0;
  
  return list;
}



/*----------------------------  function ------------------------------------
 Name: clean_up
 Purpose: Clean up dynamically allocated memory 
 Pre: None
 Post: Frees up allocated memory
 Arguments: list is the list that is being freed up
 Returns: void
 Calls: free
 ----------------------------------------------------------------------------*/
void clean_up( List *list )
{

  struct NODE *curr = list->head, *tmp;
  
  while( curr ) {
    tmp = curr;
    curr = curr->next;
    free( tmp );
  }
  
  free( list );

}




/*----------------------------  function ------------------------------------
 Name: insert
 Purpose: Insert a new node into the list of specified value
 Pre: value must be integer list must not be pointing to NULL
 Post: Inserts the node of specified value into the specified list. If node
       exist in the list then it prints error message.
 Arguments: value that needs to be inserted and list into which the node will
            be inserted
 Returns: void
 Calls: contains
 ----------------------------------------------------------------------------*/
void insert( List *list, int value )
{
  if( !contains( list, value ) ) {
    
    struct NODE *curr = list->head, *prev = list->head;
    struct NODE *node = MALLOC( struct NODE );
    node->data = value;
    
    if( list->size == 0 ) {
      
      node->next = NULL;
      list->head = node;
      
    } else {
      
      while( curr && curr->data < value ) {
        prev = curr;
        curr = curr->next;
      }
      if( curr == list->head ) {
        node->next = curr;
        list->head = node;
      } else {
        prev->next = node;
        node->next = curr;
      }
      
    }
    
    (list->size)++;
    
  } else {  
    printf( "value already in list.\n" );
  }
  
}


/*----------------------------  function ------------------------------------
 Name: delete
 Purpose: To delete a node in the list
 Pre: value must be integer and list must not be pointing to NULL
 Post: Removes the node from the list if it exist otherwise prints error message
 Arguments: value of the node that will be delete and list from which it will
            be deleted
 Returns: void
 Calls: contains
 ----------------------------------------------------------------------------*/
void delete( List *list, int value )
{
  if( contains( list, value ) ) {
    
    struct NODE *curr = list->head, *prev = list->head;
    
    while( curr ) {
      if( curr->data == value ) {
        if( curr == list->head ) {
          list->head = list->head->next;
        } else {
          prev->next = curr->next;
          free( curr );
        }
        break;
      }
      prev = curr;
      curr = curr->next;
    }
    
  } else {
    printf( "Value %d not in list.\n", value );
  }
		
}



/*----------------------------  function ------------------------------------
 Name: is_empty
 Purpose: Determines whether list is empty
 Pre: None
 Post: Determines whether list is empty or not
 Arguments: list that is checked to be empty
 Returns: True if list is empty false otherwise
 Calls: None
 ----------------------------------------------------------------------------*/
bool is_empty( List *list )
{
  return list->size == 0;
}



/*----------------------------  function ------------------------------------
 Name: contains
 Purpose: To determine if list contains the node of specified value
 Pre: list must not point to NULL
 Post: Determines whether list contains node of specified value
 Arguments: value that is being checked to exist in specified list
 Returns: True if list contains the node of specified value, otherwise false
 Calls: None
 ----------------------------------------------------------------------------*/
bool contains( List *list, int value )
{
  struct NODE *curr = list->head;
  bool contains = false;
  
  while( curr ) {
    if( curr->data == value ) {
      contains = true;
      break;
    }
    curr = curr->next;
  }
  
  return contains;
}



/*----------------------------  function ------------------------------------
 Name: print_list
 Purpose: Prints the list
 Pre: None
 Post: Prints the list
 Arguments: list that will be printed
 Returns: void
 Calls: None
 ----------------------------------------------------------------------------*/
void print_list( List *list )
{
  struct NODE *curr = list->head;
  printf( "List Values:\n" );
  while( curr ) {
    printf( "%d\n", curr->data );
    curr = curr->next;
  }
	
}



/*----------------------------  function ------------------------------------
 Name: print_list_prompt
 Purpose: To print out the list and prompt message after printing list
 Pre: None
 Post: Prints the list and prompt message
 Arguments: list is a pointer the list is being printed
 Returns: void
 Calls: print_list
 ----------------------------------------------------------------------------*/
void print_list_prompt( List *list )
{
  print_list( list );
  printf("Enter 0 to delete node, 1 to add node, or 2 to quit.\n");
}



/*--------------------------- main function ----------------------------------
 Purpose: Start the program
 Pre: None
 Post: Table of values of pythagorean triples
 Arguments: None
 Returns: EXIT_SUCCESS
 Calls: create_list, insert, delete, print_list_prompt, clean_up
 ----------------------------------------------------------------------------*/
int main( )
{

  List *list = create_list();
  
  int input;
  
  insert( list, 10 );
  insert( list, 15 );
  insert( list, 5 );
  insert( list, 20 );
  
  for( print_list_prompt( list ), scanf( "%d", &input ); input != 2; 
       print_list_prompt( list ), scanf( "%d", &input ) ) {
    
    if( input == 0 ) {
      printf( "Enter data value to delete:\n" );
      scanf( "%d", &input );
      delete( list, input );
    } else if( input == 1 ) {
      printf( "Enter data value to add:\n" );
      scanf( "%d", &input );
      insert( list, input );
    } else {
      continue;
    }
  }
  
  clean_up( list );
  
  return (EXIT_SUCCESS);
	
}



