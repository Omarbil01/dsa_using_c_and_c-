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

int countdegree0(struct node *root)
{
	int x,y;

	if(root != NULL)
	{
		x=countdegree0(root->lchild);
		y=countdegree0(root->rchild);

		if(root->lchild == NULL && root->rchild ==NULL)
		{
			return x+y+1;
		}
		else
		{
			return x+y;
		}
	}
	return 0;
}


int countdegree2(struct node *root)
{
	int x,y;

	if(root != NULL)
	{
		x=countdegree2(root->lchild);
		y=countdegree2(root->rchild);

		if(root->lchild != NULL && root->rchild != NULL)
		{
			return x+y+1;
		}
		else
		{
			return x+y;
		}
	}
	return 0;
}


int countdegree1and2(struct node *root)
{
	int x,y;

	if(root != NULL)
	{
		x=countdegree1and2(root->lchild);
		y=countdegree1and2(root->rchild);

		if(root->lchild != NULL || root->rchild != NULL)
		{
			return x+y+1;
		}
		else
		{
			return x+y;
		}
	}
	return 0;
}

int countdegree1(struct node *root)
{
	int x,y;

	if(root != NULL)
	{
		x=countdegree1(root->lchild);
		y=countdegree1(root->rchild);

		if((root->lchild != NULL && root->rchild == NULL) || (root->lchild == NULL && root->rchild != NULL))
		{
			return x+y+1;
		}
		else
		{
			return x+y;
		}
	}
	return 0;

}

int main()
{
	treecreate();

	printf("Counting nodes with degree 0: \n");	
	int x=countdegree0(root);
	printf("%d ",x);
	printf("\n");


	printf("Counting nodes with degree 1: \n");	
	int y=countdegree1(root);
	printf("%d ",y);
	printf("\n");


	printf("Counting nodes with degree 1 and 2: \n");	
	int z=countdegree1and2(root);
	printf("%d ",z);
	printf("\n");


	printf("Counting nodes with degree 2: \n");	
	int w=countdegree2(root);
	printf("%d ",w);
	printf("\n");

	return 0;
}