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

void preorder(struct node *p)
{
	if(p != NULL)
	{
		printf("%d ",p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
	printf("\n");
}

void inorder(struct node *p)
{
	if(p != NULL)
	{
		preorder(p->lchild);
		printf("%d ",p->data);
		preorder(p->rchild);
	}
	printf("\n");
}

void postorder(struct node *p)
{
	if(p != NULL)
	{
		preorder(p->lchild);
		preorder(p->rchild);
		printf("%d ",p->data);
	}
	printf("\n");
}

int main()
{
	treecreate();

	printf("Preorder traversal: \n");	
	preorder(root);
	printf("\n");

	printf("Preorder traversal: \n");	
	inorder(root);
	printf("\n");

	printf("Preorder traversal: \n");	
	postorder(root);
	printf("\n");

	return 0;
}