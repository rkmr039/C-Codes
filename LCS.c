// C Program for Longest Common Sequence using Dynamic Programming
// RISHAB KUMAR 
// 5/09/2017 

#include<stdio.h>
#include<stdlib.h>
char *s1,*s2;
int **lcs,**arrows,n1,n2;
void calculateLCS()
{
  int i,j;
  arrows = (int**) malloc((n1+1)*sizeof(int*));
  for(i=0; i<=n1; i++)
  {
     arrows[i]=(int*)malloc((n2+1)*sizeof(int));
  }
  lcs = (int**) malloc((n1+1)*sizeof(int*));
  for(i=0; i<=n1; i++)
  {
     lcs[i]=(int*)malloc((n2+1)*sizeof(int));
  }
  for(i=0; i<=n1;i++)
  {
	for(j=0; j<=n2; j++)
	{
		if(i == 0 || j==0)
		{   lcs[i][j] = 0;
		    arrows[i][j]=0;
		}
		else if(s1[i]==s2[j])
		{
		    lcs[i][j] = lcs[i-1][j-1]+1;
		    arrows[i][j]=1;
		}
		else if(lcs[i-1][j]>lcs[i][j-1])
		{
		    lcs[i][j] = lcs[i-1][j];
		    arrows[i][j]=2;
		}
		else
		{
		    lcs[i][j] = lcs[i][j-1];
		    arrows[i][j]=2;
		}
	}
  }
}
void printLCS()
{
   int i,j;
   printf("Longest Common Sequence: ");
   for(i=1; i<=n2; i++)
   {
	for(j=1; j<=n2; j++)
	{
	      if(arrows[i][j] == 1)
		  {j++;printf("%c",s2[i]);}
	}
   }
}
int main()
{
	int i;
	printf("Enter size  of first and second sequence: ");
	scanf("%d%d",&n1,&n2);
	s1 = (char*) malloc(n1*sizeof(char*));
	s2 = (char*) malloc(n2*sizeof(char*));
	printf("\nEnter %d Characters for first seuence: ",n1);
	for(i=1; i<=n1; i++)
	{
	    scanf("%s",&s1[i]);
	}
	printf("\n\n");
	printf("\nEnter %d Characters for second seuence: ",n2);
	for(i=1; i<=n2; i++)
	{
	    scanf("%s",&s2[i]);
	}
	calculateLCS();
	printLCS();
	printf("\n");
 return 0;
}
