#include<stdio.h>
#include<stdlib.h>
void main(int argc, char const *argv[])
{
	int i = 0, *series,temp;
	int len   = atoi(argv[1]); // get length of fibonnacci series
	int first = atoi(argv[2]); // get first number 
	int last  = atoi(argv[3]); // gett second number
	series = (int*)malloc(len*sizeof(int)); 

	// calculate fibonacci series
	for(;i<len;i++)
	{
		series[i]=first;
		temp = first+last;
		first = last;last = temp;
		printf(" %d ",series[i]);
	}
}