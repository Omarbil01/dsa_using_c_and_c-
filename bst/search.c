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

struct node * search(int key)
{
	struct node *p=root;

	while(p != NULL)
	{
		if (key == p->data)
		{
			return p;
		}

		else if(key<p->data)
		{
			p=p->lchild;
		}

		else
		{
			p=p->rchild;
		}
	}
	return NULL;
} 

int main()
{
	insert(10);
	insert(5);
	insert(20);
	insert(8);
	insert(30);

	struct node *t=search(20);

	if(t != NULL)
	{
		printf("Element is found\n");
	}

	else
	{
		printf("Element is not found\n");
	}

	return 0;
}