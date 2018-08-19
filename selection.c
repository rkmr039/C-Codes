#include <stdio.h>
#include <stdlib.h>

void main()
{
	int i,t=0,j=0,temp,k,comparisons=0,swaps=0;
	int m;
	int array[] = {123,65,87,98,53,46,86,70,35,9,3,7,2,0,55,33,10,72,17,99,66};
	printf("\nSize of the array: %d\n",(int)(sizeof(array)/4));
	for(i=0; i<(int)(sizeof(array)/4); i++)
	{
		comparisons++;
		j=1+i;
		m = array[i];
		while(j<(int)(sizeof(array)/4))
		{
			comparisons++;
			if(m>array[j])
			{
				comparisons++;
				m = array[j];
				t=j;
			}
			j++;
		}
		temp = array[i];
		array[i]=array[t];
		array[t]=temp;
		swaps++;
	}
	for(i=0; i<(int)(sizeof(array)/4); i++)
	{printf(" %d",array[i]);}

	printf("\nComparisons: %d",comparisons);
	printf("\nSwaps: %d",swaps);
	printf("\n");
}



