//DOUBLE ENDED QUEUE

#include <stdio.h>
#include <stdlib.h>

struct queue
{
	int front;
	int rear;
	int size;
	int *Q;
};

void create(struct queue *q,int size)
{	
	q->size=size;
	q->front=-1;
	q->rear=-1;
	q->Q=(int *)malloc(q->size*sizeof(int));
}

void enqueue(struct queue *q,int x)
{
	if(q->rear==q->size-1)
	{
		printf("Queue is full\n");
	}

	else
	{
		q->rear ++;
		q->Q[q->rear]=x;
	}
}

int dequeuelastelement(struct queue *q)
{
	int x=-1;

	if(q->front == q->rear)
	{
		printf("Queue is empty\n");
	}

	else
	{
		x=q->Q[q->rear];
		q->rear --;

	}
	return x;
}

int dequeuefirstelement(struct queue *q)
{
	int x=-1;

	if(q->front == q->rear)
	{
		printf("Queue is empty\n");
	}

	else
	{
		q->front ++;
		x=q->Q[q->front];

	}
	return x;
}

void display(struct queue q)
{
	for(int i=q.front+1;i<=q.rear;i++)
	{
		printf("%d ",q.Q[i]);
	}
	printf("\n");
}

int main()
{
	struct queue q;
	create(&q,5);

	printf("Enqueue: \n");
	enqueue(&q,5);
	enqueue(&q,7);
	enqueue(&q,9);
	enqueue(&q,2);
	enqueue(&q,4);
	display(q);
	printf("\n");

	printf("Dequeue from front: \n");
	int x=dequeuefirstelement(&q);
	printf("Deleted element: %d\n",x);
	display(q);
	printf("\n");

	printf("Dequeue from rear: \n");
	int y=dequeuelastelement(&q);
	printf("Deleted element: %d\n",y);
	display(q);
	printf("\n");

	free(q.Q);
	return 0;
}