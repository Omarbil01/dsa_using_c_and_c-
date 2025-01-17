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

void reverse(struct node *p)
{
	struct node *q,*r;
	q=NULL;
	r=NULL;

	while(p != NULL)
	{
		r=q;
		q=p;
		p=p->next;
		//we are reversing the links of all the nodes here
		//we will be hopping
		//first iteration,r will remain null,q and p will point towards
		//same node at first, then p will point towards next node
		//in the first node q->next will be NULL as after reverse
		//first node should not point anywhere

		//it will keep happening, r will point at q, while q and p will 
		//point at next nodes,q is at node 2, p at node 3, r at node 1
		//q next will point at r, which will always be the node behind
		//q, this will keep happening till p reaches NULL, where the 
		//iteration will happen last time
		q->next=r;
	}
	first=q;
	//as after last iteration, pointer p is not pointing towards any
	//node,q is the pointer which is pointing at first node,which was last node 
	//of original list, so first will make sure all list structs are listed and 
	//is used in reverse and display function in main function
}

int main()
{
	int a[]={10,20,30,40,50};

	set(a,5);

	printf("Default link list: ");
	printf("\n");
	display(first);
	printf("\n\n");

	printf("Link list after reverse: ");
	printf("\n");
	reverse(first);
	display(first);
	printf("\n");

	freeList(first);

	return 0;
}