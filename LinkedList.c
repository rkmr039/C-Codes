#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
	struct node *link;
	int info;
};
struct node *START = NULL;
struct node* createNode()
{
	struct node* n;
	n = (struct node*)malloc(sizeof(struct node));
	return n;
}

void traverse()
{
	struct node *temp;
	if (START == NULL)
	{
		printf("\nList is Empty\n");
	}
	else
	{
		temp = START;
		while(temp != NULL) 
		{
			printf("%d | ",temp->info);
			temp=temp->link;
		}
	}
}
void insertAtEnd()
{
	struct node *temp, *t;
	int value;
	temp = createNode();
	temp->link = NULL;
	printf("\nEnter value want to insert: \n");
	scanf("%d",&value);temp->info = value;
	if(START == NULL)
		START = temp;
	else
	{
		t=START;
		while(t->link != NULL)
			t=t->link;
		t->link = temp;
		printf("\nNode inserted\n");
	}
}
void deleteAtFirst()
{
	struct node *temp;
	if(START == NULL)
		printf("\nList is Empty\n");
	else
	{
		temp=START;
		START=START->link;
		free(temp); // free(r->link);
	}
}
int main()
{
	int option;
	printf("\n\t================Linked list===================\n");
	while(1)
	{
		printf("\n1.InsertAtEnd\n2.DeleteAtFirst\n3.Traverse\n4.Exit\nEnter your Choice: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				insertAtEnd();
				break;
			case 2:
				deleteAtFirst();
				break;
			case 3:
				traverse();
				break;
			case 4:
				exit(0);
			default: 
				printf("\nInvalid Input \n");
		}
	}
	return 0;
}