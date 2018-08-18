/*
		Circular QUEUE implementation using Dynamic Array
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int *QUEUE = NULL;
int front = 0;
int rear = 0;
int len;
int GetCurrentSize();
void enQueue();
int deQueue();
void DisplayQueue();

void main()
{
	int option,temp;
	printf("\n===============Circular Queue================\n\n");
	printf("\nEnter the len of the QUEUE : ");
	scanf("%d",&len);
	QUEUE = (int*)malloc(sizeof(int)*len);

	while(1)
	{
		printf("\n1.Insertion\n2.Deletion\n3.Display Queue\n4.Exit ");
		printf("\nEnter Your Choice: ");scanf("%d",&option);

		switch(option)
		{
			case 1:
				enQueue();
				break;
			case 2:
				temp = deQueue();
				if(temp !=(int)NULL)
					printf("\nDe Queued Item: %d\n",temp);
				break;
			case 3:
				DisplayQueue();
				break;
			case 4:
				exit(0);
		}
	}
}
void enQueue()
{
	int temp;
	// check if the QUEUE is full
	if (((front+rear)-1)%len == 0)
	{
		printf("\nOverflow\n");
	}
	else // else insert
	{
		// if the QUEUE is empty
		printf("\nEnter Value: ");scanf("%d",&temp);
		if(front == 0)
			{front = 1;rear=1;}
		else
		{
			rear++;
			if(rear > len) rear = 1;			
		}
		QUEUE[rear] = temp;
	}
}
int deQueue()
{
	int temp = NULL;
	// check if the QUEUE is already empty
	if(front == 0)
	{
		printf("\nUnderflow\n");
	}
	else // else delete 
	{
		temp = QUEUE[front];
		// check if the item is last one 
		if(front == rear)
		{
			front = 0;rear= 0 ;
		}
		else
		{
			front = (front+1)%len;
		}
		
	}
	return temp;
}
int GetCurrentSize()
{
	int size;
	if(front == 0) size=0;
	else if(rear >= front)
		size = (rear-front)+1;
	else
		size = len-((front-rear)-1);
	return size;
}
void DisplayQueue()
{
	int i,temp;
	printf("\nFRONT: %d",front);
	printf("\nREAR: %d",rear);
	if(front == 0)
	{
		printf("\nQueue is EMPTY\n");
	}
	else
	{
		
		temp = GetCurrentSize();
		printf("\nSIZE: %d",temp);
		printf("\nFRONT | ");
		i = front;
		while(temp--)
		{
			printf(" %d ",QUEUE[i]);
			i++;
			if(i>len) i=1;
		}	
		printf(" | REAR\n");
	}
}
