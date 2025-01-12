#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*first=NULL;;

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

int sum(struct node *p)
{
	int sum = 0;
	while(p != NULL)
	{
		sum = sum + p-> data;
		p=p->next;
	}
	return sum;
}

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


int main()
{
	int x,y;
	int a[]={22,44,24,37,46};

	create(a,5);
	display(first);
	x=count(first);
	y=sum(first);

	printf("Count of elements of linked list is %d\n",x);
	printf("Sum of elements of linked list id %d",y);

	printf("\n");

	free(first);

	return 0;
}