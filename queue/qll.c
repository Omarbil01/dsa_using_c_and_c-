#include<stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));

	if(t==NULL)
	{
		printf("Queue is full\n");
		return;

	}

	else
	{
		t->data=x;
		t->next=NULL;

		if(front==NULL)
		{
			front=rear=t;
		}
		else
		{
			rear->next=t;
			rear=t;
		}
	}
}

int dequeue()
{
	int x=-1;
	struct node *t;

	if(front==NULL)
	{
		printf("Queue is empty\n");
	}

	else
	{
		x=front->data;
		t=front;
		front=front->next;
		free(t);
	}
	return x;
}

void display()
{
	struct node *p=front;
	while(p != NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

int main()
{
	printf("Enqueue \n");
	enqueue(10);
	enqueue(20);
	enqueue(30);

	display();
	printf("\n");

	printf("Dequeue \n");
	int x=dequeue();
	printf("Dequeueed element: %d",x);
	printf("\n");
	display();

	printf("\n");
	return 0;
}