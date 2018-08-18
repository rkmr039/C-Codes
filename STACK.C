#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct ArrayStack
{
	int top;
	unsigned int size;
	int *array;
};
struct ArrayStack* createStack(int capacity)
{
	struct ArrayStack* s;
	s = malloc(sizeof(struct ArrayStack));
	s->size = capacity;
	s->top = -1;
	s->array =malloc(sizeof(int)*capacity);
	printf("\nStack Created\n");
	return s;
}

int IsEmpty(struct ArrayStack *s)
{
	if (s->top == -1)
	{
		return 1;
	}
	else return 0;
}
int IsFull(struct ArrayStack *s)
{
	if (s->size-1 == s->top)
	{
		return 1;
	}
	else
		return 0;
}
void push(struct ArrayStack *s,int item)
{
	if(! IsFull(s))
	{
		s->top++;
		s->array[s->top] = item;
		printf("\nInserted sucessfully\n");
	}
	else
	{
		printf("\nStack is FUll \n");
	}
}
int pop(struct ArrayStack *s)
{
	int item=-1;
	if(!IsEmpty(s))
	{
		item = s->array[s->top];
		s->top--;
	}
	else{
		printf("\nStack is Empty\n");
	}
	return item;
}
int getTop(struct ArrayStack *s)
{
	return s->array[s->top];
}
void printStack(struct ArrayStack *s)
{
	int i = s->top;printf("\n\n");
	while(i>-1)
	{
		printf("%d | ",s->array[i]);
		i--;
	}
}
void main()
{
	int option,temp;
	struct ArrayStack *s;clrscr();
	printf("\n\n===========Stack=============\n");
	s = createStack(5);
	while(1)
		{
			printf("\n1.Push\n2.Pop\n3.IsFull\n4.IsEmpty\n5.Top\n6.Print Stack\n7.Exit\n");
			printf("Enter your choice: ");scanf("%d",&option);
			switch(option)
			{
				case 1:
					printf("\nEnter value: \n");scanf("%d",&temp);
					push(s,temp);printStack(s);
					break;
				case 2:
					temp = pop(s);
					if(temp != -1)
					 printf("\nPoped out: %d",temp);
					 printStack(s); 
					break;
				case 3:
					if(IsFull(s) != 1)
						printf("\nStack is not full\n");
					else
						printf("\nStack is full\n");
					break;
				case 4:
					if(IsEmpty(s) != 1)
						printf("\nStack is not Empty\n");
					break;
				case 5:
					temp = getTop(s);
					printf("\n%d\n",temp);
					break;
				case 6:
					printStack(s);
					break;
				case 7:
					exit(0);
				default: 
					printf("\nInvalid Input \n");
			}
		}getch();
}
