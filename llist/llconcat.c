#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*first=NULL,*second=NULL,*third=NULL;

void set(int a[],int n)
{
	struct node *t,*last;
	int i;

	first=(struct node *)malloc(sizeof(struct node));
	first->data=a[0];
	first->next=NULL;
	last=first;

	for(i=1;i<n;i++)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=a[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}

void set2(int a[],int n)
{
	struct node *t,*last;
	int i;

	second=(struct node *)malloc(sizeof(struct node));
	second->data=a[0];
	second->next=NULL;
	last=second;

	for(i=1;i<n;i++)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=a[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}

void set3(int a[],int n)
{
	struct node *t,*last;
	int i;

	third=(struct node *)malloc(sizeof(struct node));
	third->data=a[0];
	third->next=NULL;
	third=first;

	for(i=1;i<n;i++)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=a[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}

void display(struct node *p)
{
	while(p != NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}

void freeList(struct node *p)
{
	struct node *temp;
	while(p != NULL)
	{
		temp=p;
		p=p->next;
		free(temp);
	}
}

void concat(struct node *p,struct node *q)
{
	third=p;
	//pointer third iis pointing towards p because
	//new node will be created,i.e- concat, which 
	//will start from pointer node third

	while(p->next != NULL)
	//we have to make sure we are at the last
	//data node
	{
		p=p->next;
	}
	p->next=q;
	//after reaching last data node, we will point 
	//p->next which was null to second linked list 
	//first node address
}

int main()
{
	int a[]={1,4,66,72,99};
	set(a,5);

	display(first);
	printf("\n");

	int b[]={3,5,67,77,93};
	set2(b,5);

	display(second);
	printf("\n");

	printf("After concat: ");
	concat(first,second);
	display(third);
	printf("\n");

	freeList(third);
	return 0;
}