// Factorial using recursion
#include<stdio.h>
int factorial(int num)
{
    if( num <= 0) return 1;
    return num * factorial(num - 1);
}

int main()
{
    int num;
    printf("\nEnter number : ");
    scanf("%d",&num);
    printf("%d",factorial(num));
    return 0;
}
