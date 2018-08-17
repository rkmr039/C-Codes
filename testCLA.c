#include <stdio.h>
#include <string.h>
main(int argc, char *argv[])
{
	int i;
	printf("\nNo of Arguments: %d\n",argc);
	for(i=0; i<argc; i++)
	{
		printf("\n%s",argv[i]);
	}getch();
}