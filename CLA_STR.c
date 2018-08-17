#include<stdio.h>

int main(int argc, char *argv[])
{
	char *ptr = argv[1];
	int len=0;
	while(*ptr != '\0')
	{
		len++; // get string length
		ptr++;// increase pointer upto last character 
	}
	ptr--; // avoid '\0' at end of string 
	while(len--) // while length > 0 
	{
		printf("%c",*ptr);ptr--;
	}
	return 0;
}
