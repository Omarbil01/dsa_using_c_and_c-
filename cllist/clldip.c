#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*head;

void set(int a[],int n)
{
	int i;
	struct node *t,*last;

	head=(struct node *)malloc(sizeof(struct node));
	head->data=a[0];
	head->next=head;
	//as it is a circular linked list,next will point to next node
	//if there is only one node next will point to that node
	last=head;

	for(i=1;i<n;i++)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=a[i];
		t->next=last->next;
		//now we have one more node,we have to link it
		//to next node, for 2 elements,basically t is last node for
		//now so we are linking it at head
		last->next=t;
		//last.next is not pointing anywhere,so we will connect prev
		//and current nodes using it
		last=t;
	}
}

void display(struct node *p)
{
	do
	{
		printf("%d ",p->data);
		p=p->next;
	}while(p != head);
}

void freeList(struct node *temp)
{
	if(head == NULL)
	{
		return;
	}

	temp=head;
	do
	{
		struct node *nn=temp->next;
		free(temp);
		temp=nn;
	}while(temp != head);
}


int main()
{

	int a[]={2,3,4,5,6};
	set(a,5);

	printf("Linked list: ");
	display(head);
	printf("\n");

	freeList(head);
	return 0;
}