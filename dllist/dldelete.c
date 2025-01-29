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

int len(struct node *p)
{
	int l=0;
	while(p != NULL)
	{
		l++;
		p=p->next;
	} 
	return l;
}

void delete(struct node *p,int index)
{
	struct node *t;
	int i,x;

	if(index<=0 || index>len(p))
	{
		return;
	}

	if(index == 1)
	{
		first=first->next;
		if(first != NULL)
		{
			first->prev=NULL;
		}
		x=p->data;
		free(p);
	}
	else
	{
		for(i=00;i<index-1;i++)
		{
			p=p->next;
		}
		p->prev->next=p->next;
		if(p->next != NULL)
		{
			p->next->prev=p->prev;
		}
		x=p->data;
		free(p);
	}	
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
	int y;
	int a[]={10,20,30,40,50};

	create(a,5);

	printf("Linked list: ");
	display(first);
	printf("\n");

	printf("Enter the index you want to delete at: ");
	scanf("%d",&y);
	delete(first,y);

	printf("Linked list deletion: ");
	display(first);
	printf("\n");

	freeList(first);
	return 0;
}