// swap function using macros defination 
#include <stdio.h>
#include <stdlib.h>

// using XOR ^ operator
#define SWAP(a,b) {a ^= b; b ^= a; a ^= b;}
// using addition + and subtraction - operator 
#define SWAPAB(a,b) {a += b; b = a-b; a -= b;}
int main()
{
	int x = 5;
	int y = 10;
	printf("x: %d y:%d\n",x,y);
	SWAP(x,y);
	printf("x: %d y:%d\n",x,y);
	SWAPAB(x,y);
	printf("x: %d y:%d\n",x,y);

	return 0;
} 