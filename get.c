// use of getenv()  get enviroment variable name 
// The C library function char *getenv(const char *name) searches
// for the environment string pointed to by name and returns the associated
// value to the string.
// This function returns a null-terminated string with the value of the requested 
// environment variable, or NULL if that environment variable does not exist.

#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("\nPATH: %s\n", getenv("PATH"));
	printf("\nHOME: %s\n", getenv("HOME"));	
	printf("\nROOT: %s\n", getenv("ROOT"));

	return 0;
}