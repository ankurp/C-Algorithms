/*
 Program Name: itox.c
 Author: Ankur Patel
 Program Intent: To convert int to the base number
 */

#include <stdio.h>

static char table[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

void convert( int, int );

int main()
{
	int num, base;

	printf("Enter number to be converted: ");
	scanf("%d", &num);
	printf("Enter base: ");
	scanf("%d", &base);
	
	if( num < 0 || base < 0 || base > 16 ) {
		printf( "Error\n" );
		return -1;
	}
	
	convert( num, base );
	printf("\n");
}

void convert( int num, int base )
{

	if( num >= base ) {
		convert( num/base, base );
	}
	printf( "%c", table[ num % base ] );
	
}
