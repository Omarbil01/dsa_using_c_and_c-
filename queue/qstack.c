#include <stdio.h>
#include <stdlib.h>

struct stack 
{
    int top;
    int *a;
    int size;
};


struct queue 
{
    struct stack s1; 
    struct stack s2;
};

void create(struct stack *st, int size) {
    st->size = size;
    st->top = -1;
    st->a = (int * )malloc( st->size * sizeof(int));
}

void push(struct stack *st, int x) 
{
    if (st->top == st->size - 1) 
    {
        printf("Stack Overflow\n");
    } 
    else 
    {
        st->top++;
        st->a[st->top] = x;
    }
}

int pop(struct stack *st) 
{
    if (st->top == -1) 
    {
        printf("Stack Underflow\n");
        return -1;
    } 
    else 
    {
        return st->a[st->top--];
    }
}

int isEmpty(struct stack *st) 
{
    return st->top == -1;
}


void enqueue(struct queue *q, int x) 
{
    push(&q->s1, x);
}

int dequeue(struct queue *q) 
{
    if (isEmpty(&q->s2)) 
    {
        while (!isEmpty(&q->s1)) 
        {
            push(&q->s2, pop(&q->s1));
        }
    }
    return pop(&q->s2);
}

void display(struct queue *q) 
{
    if (!isEmpty(&q->s2)) 
    {
        for (int i = q->s2.top; i >= 0; i--) 
        {
            printf("%d ", q->s2.a[i]);
        }
    }
    for (int i = 0; i <= q->s1.top; i++) 
    {
        printf("%d ", q->s1.a[i]);
    }
    printf("\n");
}

int main() 
{
    struct queue q;
    create(&q.s1, 10);
    create(&q.s2, 10);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printf("Queue after enqueues: ");
    display(&q);
    
    printf("Dequeued: %d\n", dequeue(&q));
    
    printf("Queue after dequeue: ");
    display(&q);

    free(q.s1.a);
    free(q.s2.a);
    
    return 0;
}
