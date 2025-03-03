#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

struct node *root=NULL;

void treecreate()
{
	node *p;
	node *r;
	int x;
	struct queue q;

	create(&q,100);

	printf("Enter root value: ");
	scanf("%d",&x);
	root=(struct node *)malloc(sizeof(struct node));
	root->data=x;
	root->lchild=NULL;
	root->rchild=NULL;
	enqueue(&q,root);

	while(!isEmpty(q))
	{
		p=dequeue(&q);
		printf("Enter value of left child of %d(Enter -1 if no value): ",p->data);
		scanf("%d",&x);

		if(x != -1)
		{
			r=(struct node *)malloc(sizeof(struct node));
			r->data=x;
			r->lchild=NULL;
			r->rchild=NULL;
			p->lchild=r;
			enqueue(&q,r);
		}

		printf("Enter value of right child of %d(Enter -1 if no value): ",p->data);
		scanf("%d",&x);

		if(x != -1)
		{
			r=(struct node *)malloc(sizeof(struct node));
			r->data=x;
			r->lchild=NULL;
			r->rchild=NULL;
			p->rchild=r;
			enqueue(&q,r);
		}
	}
}

int count(struct node *root)
{
	if(root != NULL)
	{
		return count(root->lchild)+count(root->rchild)+1;
	}
}

int height(struct node *root)
{
	int x=0;
	int y=0;

	if(root == 0)
	{
		return 0;
	}

	x=height(root->lchild);
	y=height(root->rchild);

	if(x>y)
	{
		return x+1;
	}
	else
	{
		return y+1;
	}
}

int main()
{
	treecreate();

	printf("Counting number of nodes: \n");	
	int x=count(root);
	printf("%d ",x);
	printf("\n");

	printf("Height of the tree: \n");	
	int y=height(root);
	printf("%d ",y);
	printf("\n");

	return 0;
}