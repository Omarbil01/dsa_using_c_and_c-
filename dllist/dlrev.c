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

void reverse(struct node *p)
{
	struct node *temp;

	while(p != NULL)
	{
		temp=p->next;
		p->next=p->prev;
		p->prev=temp;
		//swapping of links take place, as 
		//reverse is just swapping the links

		if(temp == NULL)
		{
			first=p;
			//the last node becomes first
			//and during display, the last
			//node will be first node
		}
		p=temp;
		// this line will move the pointers to 
		// the next node
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

	reverse(first);

	printf("Linked list after reverse: ");
	display(first);
	printf("\n\n");

	freeList(first);
	return 0;
}
