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

struct node *inpre(struct node *p)
{
	while(p != NULL && p->rchild != NULL)
	{
		p=p->rchild;
	}
	return p;
}

struct node *insuc(struct node *p)
{
	while(p != NULL && p->lchild != NULL)
	{
		p=p->lchild;
	}
	return p;
}

struct node * delete(struct node *p,int x)
{
	struct node *q;
	if(p == NULL)
	{
		return NULL;
	}

	if(p->lchild == NULL && p->rchild == NULL)
	{
		if(p == root)
		{
			root = NULL;
		}
		free(p);
		return NULL;
	}

	if(x < p->data)
	{
		p->lchild=delete(p->lchild,x);
	}

	else if(x > p->data)
	{
		p->rchild=delete(p->rchild,x);
	}

	else
	{
		if(height(p->lchild)>height(p->rchild))
		{
			q=inpre(p->lchild);
			p->data=q->data;
			p->lchild=delete(p->lchild,q->data);
		}

		else
		{
			q=insuc(p->rchild);
			p->data=q->data;
			p->rchild=delete(p->rchild,q->data);

		}
	}
	return p;
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

	struct node *a=delete(root,20);

	if(a == NULL)
	{
		printf("No element deleted\n\n");
	}
	else
	{
		printf("Element deleted\n\n");
	}

	printf("After deletion: \n");
	inorder(root);
	printf("\n");
	
	return 0;
}
