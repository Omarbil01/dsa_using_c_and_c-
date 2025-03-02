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

void levelorder(struct node *p)
{
	struct queue q;
	create(&q,100);

	printf("%d ",p->data);
	enqueue(&q,p);

	while(!isEmpty(q))
	{
		p=dequeue(&q);
		if(p->lchild)
		{
			printf("%d ",root->lchild->data);
			enqueue(&q,p->lchild);
		}
		if(p->rchild)
		{
			printf("%d ",root->rchild->data);
			enqueue(&q,p->rchild);
		}
	}

}

int main()
{
	treecreate();

	printf("Level order traversal: \n");	
	levelorder(root);
	printf("\n");

	return 0;
}