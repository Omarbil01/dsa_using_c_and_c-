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

	first->data=a[i];
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

void delnode(struct node *p,int y)
{
	struct node *q=NULL;
	int i;
	int x=-1;

	if(y<1 || y>count(p))
	{
		//if index is not in ranges
		return;
	}
	if(y == 1)
	{
		//delting for first index
		q=first; 
		//newly created node q is pointing to first node
		x=first->data;
		//the first data is at variable x
		first=first->next;
		//then first will be the second element in list
		//making it not part of the list but pointer q 
		// is pointing towards that node
		free(q);
		//now we will free the node memory and the node is deleted
	}
	else
	{
		for(i=0;i<y-1;i++)
		//i=0 means that the pointers are at their initial locations 
		//from i=1 they will start moving to next locations
		{
			q=p;
			p=p->next;
			//q will be at the node t was in and t
			//will move to next node till they are in 
			//position-1 index to delete
		}
		q->next=p->next;
		//we have to break the link so q will point to 
		//node after t
		x=p->data;
		//variable x will have data of t, so freeing of memory can take place
		free(p);
		//then we will free node t
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
	int y;
	int a[]={1,4,66,72,99};
	set(a,5);

	display(first);
	printf("\n");

	printf("Enter the index you want to delete: ");
	scanf("%d",&y);

	delnode(first,y);
	display(first);
	printf("\n");

	freeList(first);
	return 0;
}