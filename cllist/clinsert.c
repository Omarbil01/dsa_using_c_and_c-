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

void insert(struct node *p, int index, int x) {
    struct node *t;
    int i;

    if (index < 0 || index > length(head)) 
    {
        return;
    }

    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;

    if (index == 0) 
    {
        if (head == NULL) 
        { 
            head = t;
            t->next = head;
        } 
        else 
        { 
            while (p->next != head) 
            {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    } 
    else 
    { 
        for (i = 0; i < index - 1; i++) 
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}



int main()
{
	int x;
	int index;
	int a[]={2,3,4,5,6};
	set(a,5);

	printf("Linked list: ");
	display(head);
	printf("\n");

	printf("Enter the index you want to insert element: ");
	scanf("%d",&index);
	printf("Enter the value you want to insert: ");
	scanf("%d",&x);
	insert(head,index,x);
	printf("\n");

	printf("Linked list after insertion: ");
	display(head);
	printf("\n");

	freeList(head);
	return 0;
}