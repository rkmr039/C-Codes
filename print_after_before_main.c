// printf before main execution

#include <stdio.h>
#include <limits.h>


// using attribute constructor and destructor 

void DISPALY_BEFORE_MAIN() __attribute__ ((constructor));
void DISPALY_AFTER_MAIN() __attribute__ ((destructor));

void DISPALY_BEFORE_MAIN()
{
	printf("\n\t\t\t\tBEFORE MAIN using constructor\n");
}
void DISPALY_AFTER_MAIN()
{
	printf("\n\t\t\t\tAFTER MAIN using destructor\n");
}

/*
// using #pragma directive
void BEFORE_MAIN();
void AFTER_MAIN();

#pragma startup BEFORE_MAIN()
#pragma exit AFTER_MAIN()

void BEFORE_MAIN()
{
	printf("\n\t\t\t\tBEFORE MAIN using #pragma directive\n");
}
void AFTER_MAIN()
{
	printf("\n\t\t\t\tAFTER MAIN using #pragma directive\n");
}

*/

int main()
{
	printf("\n\t\t\t\t MAIN\n");

	return 0;
}
