// use of operator #

#include <stdio.h>
#include <stdlib.h> 

// use as stringize operator,
// macro ToString return String of it's argument 
#define ToString(s) #s 

// token pasting operator in used to concatenate two perameters 
// return a string 
#define CONCAT(a,b) a ## b


int main()
{
	int ab = 55;
	char d = '1';
	
	// stringize
	printf(ToString(Rishab Kumar));
	printf("\n");
	printf("\n%d",((sizeof(ToString(Rishab)))-1));

	// token pasting, concatination operator, merging operator
	// digit = CONCAT(a,b);
	printf("\n%d",CONCAT(a,b));printf("\n");
	return 0;
}
