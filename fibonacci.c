// Fibonacci using recursion
// Complexity : O(n)
#include<stdio.h>
int fibonacci(int num)
{
    if( num <= 1) return num;
    return fibonacci(num - 1) + fibonacci(num - 2);
}

int main()
{
    int num;
    printf("\nEnter size of Fibonacci Series: ");
    scanf("%d",&num);
    printf("%d",fibonacci(num));
    return 0;
}
