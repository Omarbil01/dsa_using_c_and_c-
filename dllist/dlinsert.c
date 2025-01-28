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

void insert(struct node *p,int index,int x)
{
	struct node *t;
	int i;

	if(index<0 || index>len(p))
	{
		return;
	}
	if(index == 0)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=x;
		t->prev=NULL;
		t->next=first;
		first->prev=t;
		first=t;
	}
	else
	{
		for(i=0;i<index-1;i++)
		{
			p=p->next;
		}
			t=(struct node *)malloc(sizeof(struct node));
			t->data=x;

			t->prev=p;
			t->next=p->next;
			if(p->next != NULL)
			{
				p->next->prev=t;
				p->next=t;
			}
		
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
	int x,y;
	int a[]={10,20,30,40,50};

	create(a,5);

	printf("Linked list: ");
	display(first);
	printf("\n");

	printf("Enter the element you want to insert: ");
	scanf("%d",&x);
	printf("Enter the index you want to insert at: ");
	scanf("%d",&y);
	insert(first,y,x);

	printf("Linked list after insertion: ");
	display(first);
	printf("\n");

	freeList(first);
	return 0;
}