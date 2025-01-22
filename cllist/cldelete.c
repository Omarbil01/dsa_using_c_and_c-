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
	last=head;

	for(i=1;i<n;i++)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=a[i];
		t->next=last->next;
		last->next=t;
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

int length(struct node *p)
{
	int len=0;
	do
	{
		p=p->next;
		len ++;
	
	}while(p != head);
	return len;
}

void delete(struct node *p,int index)
{
	int x;
	struct node *q;

	if(index<=0 || index>length(head))
	{
		return;
	}

	if(index == 1)
	{
		while(p->next != head)
		{
			p=p->next;
		}
		x=head->data;
		if(head == p)
		{
			free(head);
			head=NULL;
		}
		else
		{
			p->next=head->next;
			free(head);
			head=p->next;
		}
	}
	else
	{
		for(int i=0;i<index-2;i++)
		{
			p=p->next;
		}
		q=p->next;
		p->next=q->next;
		x=q->data;
		free(q);
	}

}

int main()
{
	int index;
	int a[]={2,3,4,5,6};
	set(a,5);

	printf("Linked list: ");
	display(head);
	printf("\n");

	printf("Enter the index you want to delete: ");
	scanf("%d",&index);
	delete(head,index);
	printf("\n");

	printf("Linked list after deletion: ");
	display(head);
	printf("\n");

	freeList(head);
	return 0;
}