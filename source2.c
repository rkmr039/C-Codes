#include<stdio.h>
#include<conio.h>
 int count = 5;

void main()
{
	//clrscr();
	printf(" S2 Count : %d\n",count);
	count = write_extern();
	printf("\n S2 Count : %d",count);
	getch();
}