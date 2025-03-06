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

void inorder(struct node *p)
{
	//gives sorted order of element
	if(p != NULL)
	{
		inorder(p->lchild);
		printf("%d ",p->data);
		inorder(p->rchild);
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
	return 0;
}