#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

int main(int argc, char *argv[])
{
	char *ptr = argv[1];
	int len=0;
	int i;

	while(*ptr != '\0')
	{
		len++;
		ptr++;
	}
	ptr--;
	while(len--)
	{
		printf("%c",*ptr);ptr--;
	}

	return 0;
}