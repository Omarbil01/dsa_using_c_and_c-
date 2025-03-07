#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *lchild;
	int data;
	struct node *rchild;
};

struct node *root=NULL;

void insert(int key)
{
	struct node *t=root;
	struct node *r=NULL;
	struct node *p;

	p=(struct node *)malloc(sizeof(struct node));
	p->data=key;
	p->lchild=NULL;
	p->rchild=NULL;

	if(root == NULL)
	{
		root=p;
		return;
	}

	while(t != NULL)
	{
		r=t;

		if(key < t->data)
		{
			t=t->lchild;
		}

		else if(key > t->data)
		{
			t=t->rchild;
		}

		else
		{
			return;
		}
	}

	
		if(key < r->data)
		{
			r->lchild=p;
		}

		else
		{
			r->rchild=p;
		}
	
}

int height(struct node *p)
{
	int x,y;
	if(p == NULL)
	{
		return 0;
	}

	x=height(p->lchild);
	y=height(p->rchild);

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
	insert(10);
	insert(5);
	insert(20);
	insert(8);
	insert(30);

	printf("Inorder traversal: \n");
	inorder(root);
	printf("\n");

	int x=height(root);
	printf("Height of tree is: %d",x);
	printf("\n");

	return 0;
}