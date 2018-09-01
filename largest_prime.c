/*
INPUT: string containing the sorted array 
INPUT: 1,2,3,4,5,6,13,29

OUTPUT: largest prime number from given string
OUTPUT: 29


Get input of string of unknown length from STDIN

COMPLEXITY: O(n)

*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
char *pStr;
unsigned int len = 0 ;
unsigned int len2 = 0 ;
int *a;
void GetString()
{
    unsigned int len_max = 128;
    unsigned int current_size = 0;

    pStr = malloc(len_max);
    current_size = len_max;
    int c;
    if(pStr != NULL)
    {
    //accept user input until hit enter or end of file
	while (( c = getchar() ) != '\n')
	{
		pStr[len++]=(char)c;

		//if len reached maximize size then realloc size
		if(len == current_size)
		{
            current_size = len+len_max;
			pStr = realloc(pStr, current_size);
		}
	}
	pStr[len] = '\0';
    }
}
void GetIntArray()
{
    int temp = len,i=0,j=0,k=0 ;
    char temporary[256];
    a = (int*)malloc(sizeof(int)*temp);
    while(temp--)
    {
        if(pStr[i] != ',')
          {
              temporary[k] = pStr[i];k++;
          }
        else
        {
          a[j] = atoi(temporary);j++;k=0;
        }i++;
    }
    a[j] = atoi(temporary);j++;k=0;
    len2 = j;
}
void FreeString()
{
  free(pStr);
	pStr = NULL;
}
void FreeIntArray()
{
   free(a);
   a = NULL;
}
void PrintString()
{
    printf("\n%s \n\n",pStr);
}

bool IsPrime(int num)
{
    bool flag = false;
    int i = 3;
    if(num == 3) flag = true;
    else if(!(num % 2 == 0))
    {
        for(;i<num; i+=2)
        {
            if(num % i == 0) flag = false;
            else flag = true;
        }
    }
    printf("\n%d\n",flag);
    return flag;
}
int main()
{
    GetString();
    GetIntArray();
    //printf("\nLEN : %d\n",len);
    //PrintString();

    int size = len2,temp,i=0;
    int max = 0;
    while( size-- )
    {
        temp = (a[i]);
        if(IsPrime(temp))
           {
               if(max < temp) max = temp;
           }
        i++;

    }
    printf("%d",max);
    FreeString();
    FreeIntArray();
    return 0;
}
