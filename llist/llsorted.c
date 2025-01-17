#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*first=NULL;

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

int isSorted(struct node *p)
{
	int x=-65536;

	while(p != NULL)
	{
		if(p->data <x)
		{
			return 0;
		}
		else
		{
			x=p->data;
			p=p->next;
		}
	}
	return 1;
}

int main()
{
	int a[]={10,20,30,40,50};

	set(a,5);

	display(first);
	printf("\n\n");

	if(isSorted(first) == 0)
	{
		printf("Not sorted\n");
	}
	else
	{
		printf("Sorted\n");
	}

	freeList(first);

	return 0;
}