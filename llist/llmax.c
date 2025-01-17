#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*first=NULL;

void display(struct node *p)
{
	while(p != NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

void create(int a[],int n)
{
	int i;
	struct node *t,*last;

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

int Max(struct node *p)
{
	int Maxm = -65535; 

	while(p != NULL)
	{
		if(p->data > Maxm)
		{
			Maxm = p->data;
		}
		p = p->next;
	}
	return Maxm;
}


int Min(struct node *p)
{
	int Minm = 65535; 

	while(p != NULL)
	{
		if(p->data < Minm)
		{
			Minm = p->data;
		}
		p = p->next;
	}
	return Minm;
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
	int a[]={22,44,24,37,46};

	create(a,5);
	display(first);
	x=Max(first);
	y=Min(first);

	printf("Maximum element of linked list is %d\n",x);
	printf("Minimum element of linked list id %d",y);

	printf("\n");

	freeList(first);

	return 0;
}