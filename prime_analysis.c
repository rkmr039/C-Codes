#include<stdio.h>
#include<malloc.h>

int *a;
int n;
void prime_analysis()
{
    int i;
    a[2]  = 1; a[3] = 1;
    a[4]  = 0; a[5] = 1;
    a[6]  = 0; a[7] = 1;

    if(n > 7)
    {
        for(i = 8; i <= n; i++)
        {
            if(i % 2 == 0) a[i] = 0;
            else
            {
                if(i % 3 == 0) a[i] = 0;
                else
                {
                    if(i % 5 == 0) a[i] = 0;
                    else
                    {
                        if(i % 7 == 0) a[i] = 0;
                        else a[i] = 1;
                    }
                }
            }
        }
    }
    for(i = 2; i <= n; i++)
        {
            if(a[i] == 1)
            {
                printf("%d\n",i);
            }
        }
}
int main()
{
    scanf("%d",&n);
    a = (int*)malloc(sizeof(int)*(n-1));
    prime_analysis();
    return 0;
}
