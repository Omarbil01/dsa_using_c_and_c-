#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node *lchild;
	int data;
	struct node *rchild;
}node;

typedef struct queue //for storing addresses of nodes
{
	int size;
	int front;
	int rear;
	node **Q;
	//for nodes then last pointer is for array
}queue;

void create(struct queue *q,int size)
{
	q->size=size;
	q->front=0;
	q->rear=0;

	q->Q=(node **)malloc(q->size*sizeof(node *));
}

void enqueue(struct queue *q,struct node *x)
{
	if((q->rear + 1)%q->size==q->front)
	{
		printf("Queue is full\n");
	}

	else
	{
		q->rear =(q->rear + 1)%q->size;
		q->Q[q->rear]=x;
	}
}

struct node * dequeue(struct queue *q)
{
	node* x=NULL;

	if(q->front == q->rear)
	{
		printf("Queue is empty\n");
	}

	else
	{
		q->front =(q->front + 1)%q->size;
		x=q->Q[q->front];
	}
	return x;
}

int isEmpty(struct queue q)
{
	return q.front == q.rear;
}

#endif