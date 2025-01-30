#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *prev;
	int data;
	struct node *next;
}*first=NULL;

void create(int a[],int n)
{
	struct node *t,*last;
	int i;

	first=(struct node *)malloc(sizeof(struct node));
	first->data=a[0];
	first->prev=first->next=NULL;
	last=first;

	for(i=1;i<n;i++)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=a[i];
		t->prev=last;
		t->next=NULL;

		last->next=t;
		last=t;
	}
}

void display(struct node *p)
{
	while(p!= NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

void freeList(struct node *p)
{
	struct node *q;

	while(p != NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
	first=NULL;
}

int main()
{
	int a[]={10,20,30,40,50};

	create(a,5);

	printf("Linked list: ");
	display(first);
	printf("\n");
	return 0;
}