#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *top=NULL;

void push(int x)
{
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));

	if(t==NULL)
	{
		printf("Stack is full\n");
	}
	else
	{
		t->data=x;
		t->next=top;
		top=t;
	}
}

void pop()
{
	struct node *t;
	
	int x=-1;

	if(top==NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		t=top;
		x=top->data;
		top=top->next;
		free(t);
	}
}

void display()
{
	struct node *p;
	p=top;

	while(p != NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

int main()
{
	push(10);
	push(20);
	push(30);

	printf("Stack is: ");
	display();
	printf("\n");

	pop();
	printf("Stack is: ");
	display();
	printf("\n");

	return 0;
}