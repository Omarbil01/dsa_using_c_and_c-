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

void merge(struct node *p,struct node *q)
{
	struct node *last;

	if(p->data < q->data)
	{
		last=third=p;
		//third will be the start of the merged pointer
		//while last will move between both structs
		p=p->next;
		//p will move to next node, so that prev node can 
		//be cut from the list for sorting
		third->next=NULL;
		//prev node is cut,last will remain with third for 
		//time being, thing it will move between both structs
	}
	else
	{
		last=third=q;
		q=q->next;
		third->next=NULL;
		//refer to if block above
	}

	while(p!=NULL && q!=NULL)
	//from here we will sort and concat
	//it will make sure that we do not 
	//move farther than p,q == null
	{
		if(p-> data < q-> data)
		{
			last->next=p;
			last=p;
			p=p->next;
			last->next=NULL;
			//after cutting the node from either p or q
			//we will check if next data of either p or q 
			//is less than data of p or q
			//if so,then last->next should point to either p and q
			//making a link, last has no place at prev node,so it will
			//reach current node, now p or q will go to their next node
			//as the process will take place again,and last->next will
			//be cut out as it will join the lowest element
		}
		else
		{
			last->next=q;
			last=q;
			q=q->next;
			last->next=NULL;
			//refer to above if statement
		}

	}
	if(p != NULL)
	{
		last->next=p;
	}
	if( q!= NULL)
	{
		last->next=q;
		//in both if statement,if there are elements remaining
		//that are not linked, then last pointer which was doing the work 
		//of linking will join to either p or q if they are not linked
	}
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

	printf("After merging: ");
	merge(first,second);
	display(third);
	printf("\n");

	freeList(third);
	return 0;
}