	/*
	QUEUE implementation using struct
	indexing starts with 0
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct ArrayQueue
{
	unsigned int capacity;
	int *array;
	int front,rear;
};

struct ArrayQueue* createQueue(int);
int deQueue(struct ArrayQueue *Q);
void enQueue(struct ArrayQueue *Q);
int GetFrontItem(struct ArrayQueue*);
int GetRearItem(struct ArrayQueue*);
int IsEmptyQueue(struct ArrayQueue *Q);
int IsFullQueue(struct ArrayQueue *Q);
int QueueSize(struct ArrayQueue *Q);
void DeleteQueue(struct ArrayQueue *Q);
void DisplayQueue(struct ArrayQueue *Q);

void main()
{
	int option,temp;
	struct ArrayQueue* Q;
	//clrscr();
	printf("\n===============Circular Queue================\n");
	printf("\nEnter the length of QUEUE: ");scanf("%d",&temp);
	Q = createQueue(temp);
	while(1)
	{
		printf("\n1.Insertion\n2.Deletion\n3.Display Queue\n4.Queue Size\n5.Exit ");
		printf("\nEnter Your Choice: ");scanf("%d",&option);

		switch(option)
		{
			case 1:
				enQueue(Q);
				break;
			case 2:
				temp = deQueue(Q);
				if(temp != (int)NULL)
					printf("\nDe Queued Item: %d\n",temp);
				break;
			case 3:
				DisplayQueue(Q);
				break;
			case 4:
				printf("\nQueue Size: %d\n",QueueSize(Q));
				break;
			case 5:
				exit(0);
			default:
				printf("\nInvalid Input\n");
		}
	}
}
struct ArrayQueue* createQueue(int size)
{
	struct ArrayQueue* Q = malloc(sizeof(struct ArrayQueue));
	Q->capacity = size;
	Q->front=Q->rear=-1;
	Q->array =(int*)malloc(sizeof(int)*size);
	printf("\n \t\tQUEUE  Created\n");
	return Q;
}
void enQueue(struct ArrayQueue *Q)
{
	int item;
	if(IsFullQueue(Q))
		printf("\n\t\tOverflow\n");
	else
	{
		printf("\nEnter Value: ");scanf("%d",&item);
		Q->rear = (Q->rear+1)%Q->capacity;
		Q->array[Q->rear] = item;
		if(Q->front == -1)
			Q->front++;
	}
}
int deQueue(struct ArrayQueue *Q)
{
	int temp = NULL;
	if(IsEmptyQueue(Q))
		{
			printf("\nUnderflow\n");
		}
	else
	{
		temp = Q->array[Q->front];
		if(Q->front == Q->rear)
			Q->front = Q->rear = -1;
		else
			Q->front = (Q->front+1)%Q->capacity;
	}
	return temp;
}
int GetRearItem(struct ArrayQueue *Q)
{
	return Q->array[Q->rear];
}
int GetFrontItem(struct ArrayQueue *Q)
{
	return Q->array[Q->front];
}
int IsEmptyQueue(struct ArrayQueue *Q)
{
	return(Q->front == -1);
}
int IsFullQueue(struct ArrayQueue *Q)
{
	return((Q->rear+1)%Q->capacity == Q->front);
}
int QueueSize(struct ArrayQueue *Q)
{
	if(IsEmptyQueue(Q)) return 0;
	else if(IsFullQueue(Q)) return Q->capacity;
	else return ( (Q->capacity - Q->front + Q->rear+1) % Q->capacity );
}
void DeleteQueue(struct ArrayQueue *Q)
{
	if(Q)
	{
		if(Q->array)
			free(Q->array);
	}
	free(Q);
}
void DisplayQueue(struct ArrayQueue *Q)
{
	int temp,i;
	printf("\nFRONT: %d",Q->front);
	printf("\nREAR: %d",Q->rear);
	if(IsEmptyQueue(Q)) printf("\n\t\tQUEUE is Empty\n");
	else
	{
		temp = QueueSize(Q);
		i = Q->front;
		printf("\nFRONT | ");
		while(temp--)
		{
			printf(" %d ",Q->array[i]);
			i = (i+1)%Q->capacity;
		}
		printf(" | REAR\n");
	}
}