/*
		Circular QUEUE implementation using Dyna,ic Array
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int *QUEUE = NULL;
int front = 0;
int rear = 0;
int len;
int GetCurrentSize();
void enQueue(int item);
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
		printf("\n1.Insertion\n2.Deletion\n3.Display Queue\n4.Current Queue Size\n5.Exit ");
		printf("\nEnter Your Choice: ");scanf("%d",&option);

		switch(option)
		{
			case 1:
				printf("\nEnter Value: ");scanf("%d",&temp);
				enQueue(temp);
				break;
			case 2:
				temp = deQueue();
				printf("\nDe Queued Item: %d\n",temp);
				break;
			case 3:
				DisplayQueue();
				break;
			case 4:
				printf("\nCurrent Size of Queue : %d\n",GetCurrentSize());
				break;
			case 5:
				exit(0);
		}
	}
}
void enQueue(int item)
{
	// check if the QUEUE is full
	if (((front+rear)-1)%len == 0)
	{
		printf("\nOverflow\n");
	}
	else // else insert
	{
		// if the QUEUE is empty
		if(front == 0)
			{front = 1;rear=1;}
		else
		{
			//GetCurrentSize();
			rear = (rear+1)%len;
			
		}
		QUEUE[rear] = item;
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
		// check if the item is last one 
		if(front == rear)
		{
			front = 0;rear= 0 ;
		}
		else
		{
			front = (front+1)%len;
		}
		temp = QUEUE[rear];
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

	printf("\nFRONT: %d",front);
	printf("\nREAR: %d",rear);
	return size;
}
void DisplayQueue()
{
	int i,temp;
	if(front == 0)
	{
		printf("\nQueue is EMPTY\n");
	}
	else
	{
		temp = GetCurrentSize();
		printf("\nFRONT | ");
		for(i=1;i<=temp;i++)
		{
			printf(" %d ",QUEUE[i]);
		}	printf(" | REAR\n");
	}
}