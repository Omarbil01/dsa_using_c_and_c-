#ifndef chains_h
#define chains_h

#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void sortinsert(struct node **a, int x)
{
	struct node *t;
	struct node *q=NULL;
	struct node *p=*a;

	t=(struct node *)malloc(sizeof(struct node));
	t->data=x;
	t->next=NULL;

	if(*a == NULL)
	{
		*a=t;
	}

	else
	{
		while(p != NULL && p->data<x)
        {
            q=p;
            p=p->next;
        }

        if(q == NULL) 
        {
            t->next = *a;
            *a = t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
	}
}

struct node *search(struct node *p,int key)
{
	while(p != NULL)
	{
		if(key == p->data)
		{
			return p;
		}

		p=p->next;
	}
	return NULL;
}

#endif
