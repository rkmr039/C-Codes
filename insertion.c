#include <stdio.h>
#include <stdlib.h>

void main()
{
	int i,j,temp,k,comparisons=0,swaps=0;
	
	int array[] = {123,65,87,98,53,46,86,70,35,9,3,7,2,0,55,33,10,72,17,99,66};
	printf("===============Insertion Sort=====================");

	printf("\nSize of array: %d",(int)(sizeof(array)/4));
	for(i=1; i<(int)(sizeof(array)/4); i++)
	{	
		temp = array[i];
		j=i-1;
		while(j>=0)
		{
			comparisons++;
			if(temp < array[j])
				{	
					swaps++;
					array[j+1]=array[j];
					array[j] = temp;
				}
			j--;
		}		
	}
	printf("\n");
	for(i=0; i<(int)(sizeof(array)/4); i++)
	{
		printf(" %d",array[i]);
	}
	printf("\n");
	printf("\nComparisons: %d",comparisons);
	printf("\nSwaps: %d",swaps);
	printf("\n");

}