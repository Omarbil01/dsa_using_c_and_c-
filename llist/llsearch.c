#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*first=NULL;

void set(int a[],int n)
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

void display(struct node *p)
{
	while(p != NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

struct node * search(struct node *p,int key)
{	
	while(p != NULL)
	{
		if(key == p->data)
		{
			return p;
		}
		else
		{
			p=p->next;
		}
	}
	return NULL;
}

int main()
{
	struct node *temp;
	int x;
	int a[]={22,17,44,39,67};
	set(a,5);

	display(first);

	printf("Enter the element you want to find: ");
	scanf("%d",&x);
	temp=search(first,x);

	if(temp != NULL)	
	{
		printf("Key is found");
	}
	else
	{
		printf("Key not found");
	}
	printf("\n");

	free(first);

	return 0;
}