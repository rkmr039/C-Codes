// Optimal Binary Search Tree Program
// Rishab Kumar   
// 02-10-2017
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void obst(int );
float *p,*q;
float **e,**w;
int **r;
int main()
{
	int i,keys;
	printf("Enter number of Keys: ");
	scanf("%d",&keys);
	p = (float*)malloc(keys*sizeof(float));
	q = (float*)malloc((keys+1)*sizeof(float));
	printf("\nEnter %d key probabilities: ",keys);
	for(i=1;i<=keys; i++)
	{
		scanf("%f",&p[i]);
		//p[i]=dp[i-1];
		//printf("%.2f\n",dp[i-1]);
	}
	printf("\nEnter %d dummy key probabilities: \n",keys+1);
	for(i=0;i<=keys; i++)
	{
		scanf("%f",&q[i]);
		//q[i]=dq[i];
		//printf("%.2f\n",dq[i]);
	}	
	obst(keys+1);
	return 0;
}  

void obst(int k)
{
	int i,j,l=k,n,loopCount=0;
	float temp;
	// 0 to k
	e = (float**)malloc((k)*sizeof(float*));
	// 1 to k
	for(i=1; i<=k; i++)
		e[i] = (float*) malloc(k*sizeof(float));
	w = (float**)malloc((k)*sizeof(float*));
	// 1 to k
	for(i=1; i<=k; i++)
		w[i] = (float*) malloc(k*sizeof(float));
	r = (int**)malloc((k)*sizeof(int*));
	// 1 to k
	for(i=1; i<=k; i++)
		r[i] = (int*) malloc(k*sizeof(int));
	while(l)
	{
		for(i=1; i<=(k-loopCount); i++)
		{
			j=(i-1)+loopCount;
			if(j==i-1) 
				{
					e[i][j]=q[i-1];w[i][j]=q[i-1];r[i][j]=0;	
				}
			else 
				{
					w[i][j]=w[i][j-1]+p[i]+q[j];
					e[i][j] = INT_MAX;
					for(n=i;n<=j;n++)
						{
							temp=e[i][n-1]+e[n+1][j]+w[i][j];
							if(temp<e[i][j]);  
								{
									e[i][j]=temp;r[i][j]=n;
								} 							
						}				
				}
		}loopCount++;l--;	
	}
	for(i=1; i<=k; i++)
	{
		for(j=0; j<k; j++)
		{
			if(i>1 && j<i-1) printf(" 0.00  ");
			else printf(" %.2f  ",e[i][j]); 
			if(j==(k-1)) printf("\n");
		}
	}
	printf("--------w matrix--------\n\n");
	for(i=1; i<=k; i++)
	{
		for(j=0; j<k; j++)
		{
			if(i>1 && j<i-1) printf(" 0.00  ");
			else printf(" %.2f  ",w[i][j]); 
			if(j==(k-1)) printf("\n");
		}
	}
	printf("-----------------\n\n");
	for(i=1; i<=k; i++)
	{
		for(j=0; j<k; j++)
		{
			if(i>1 && j<i) printf(" 0  ");
			else printf(" %d  ",r[i][j]); 
			if(j==(k-1)) printf("\n");
		}
	}
}
