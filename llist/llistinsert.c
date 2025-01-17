#include <stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}* first=NULL;

void set(int a[],int n)
{
	int i;
	struct node *t,*last;

	first=(struct node *)malloc(sizeof(struct node *));
	first->data=a[0];
	first->next=NULL;
	last=first;

	for(i=1;i<n;i++)
	{
		t=(struct node *)malloc(sizeof(struct node *));
		t->data=a[i];
		t->next=NULL;
		last->next=t;
		last =t;
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

int count(struct node *p)
{
	int count = 0;
	while(p != NULL)
	{
		count ++;
		p= p->next;
	}
	return count;
}

void insert(struct node *p,int index,int x)
{
	int i;
	struct node *t;
	if(index<0 || index>count(p))
	{
		return;
	}

	t=(struct node *) malloc (sizeof(struct node));
	t->data=x;

	if(index == 0)
	{
		t->next=first;
		first=t;
	}
	else
	{
		for(i=0;i<index-1;i++)
		{
			p=p->next;
		}
		t->next=p->next;
		p->next=t;
	}
}

void freeList(struct node *p) {
    struct node *temp;
    while (p != NULL) {
        temp = p;  
        //pointer temp is pointing towards first node  
        p = p->next; 
        //pointer p is pointing towards next node
        free(temp);  
        //now all nodes can be correctly deleted
    }
}

int main()
{
	int x,y;
	int a[]={33,44,27,11,78};

	set(a,5);
	display(first);

	printf("\n");
	printf("Enter the elements you want : ");
	scanf("%d",&x);

	printf("Enter the index you want to insert to: ");
	scanf("%d",&y);

	insert(first,y,x);
	printf("Display after insertion: ");
	display(first);

	printf("\n");

	freeList(first);

	return 0;
}