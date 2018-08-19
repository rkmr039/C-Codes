// Date Of Program: 19-08-2017

#include <stdio.h>
#include <stdlib.h>

// Compare adjacent elements and swap them if required
void bubble(int array[], int size);
void main()
{   
	int i,j,temp,comparison=0,swaps=0;
	int array[] = {123,65,87,98,53,46,86,70,35,9,3,7,2,0,55,33,10,72,17};
					
	int size = (int)(sizeof(array)/4);
	printf("\nSize of array: %d\n",size);
	bubble(array,size);
}	

void bubble(int array[], int size)
{
	int i,j,comparisons=0,swaps=0;
	printf("\n\t\t===============Bubble Sort=====================");
	for(i =0 ; i<size; i++)
	{
		for(j=0; j<size; j++)
		{
			comparisons++;
			if(array[j]>array[j+1])
			{
				swaps++;
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}	
	}
	printf("\n\n");
	for(i=0; i<size; i++)
	{
		printf(" %d ",array[i]);
	}
	printf("\nComparisons: %d",comparisons);
	printf("\nSwaps: %d\n",swaps);
}