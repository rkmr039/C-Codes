// demo of extern storage class
#include<stdio.h>

int write_extern(void);

extern int count;

int write_extern()
{
	printf("S1 Count : %d\n",count ); count++; return count;
}