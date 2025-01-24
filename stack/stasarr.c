#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int top;
	int *a;
	int size;
};

void create(struct stack *st)
{
	printf("Enter the size of the stack: ");
	scanf("%d",&st->size);
	st->top=-1;

	st->a=(int *)malloc(st->size*sizeof(int));
}

void display(struct stack st)
{
	int i;
	for(i = st.top;i>=0;i--)
	{
		printf("%d ",st.a[i]);
	}
	printf("\n");
}

void push(struct stack *st,int x)
{
	if(st->top > st->size-1)
	{
		printf("Overflow\n");
	}
	else
	{
		st->top++;
		st->a[st->top]=x;
	}
}

void pop(struct stack *st)
{
	int x=-1;

	if(st->top == -1)
	{
		printf("Underflow\n");
	}
	else
	{
		x=st->a[st->top];
		st->top--;
	}
}

int isEmpty(struct stack st)
{
	if(st.top == -1)
	{
		return 1;
	}
	return 0;
}

int isFull(struct stack st)
{
	return st.top == st.size - 1;
}

int peek(struct stack st)
{
	if(!isEmpty(st))
	{
		return st.a[st.top];
	}
	return -1;
}

int main()
{
	struct stack s1;

	create(&s1);

	push(&s1,10);
	push(&s1,20);
	push(&s1,30);
	push(&s1,40);

	printf("Stack after push: ");
	display(s1);
	printf("\n");

	printf("Top element:%d",peek(s1));
	printf("\n");

	int x = isFull(s1);
	printf("Stack is full or not:%d ",x);
	printf("\n");

	int y=isEmpty(s1);
	if(y == -1)
	{
		printf("Stack is empty");
		printf("\n");
	}
	else
	{
		printf("Stack is not empty");
		printf("\n");
	}

	pop(&s1);

	printf("Stack after pop: ");
	display(s1);
	printf("\n");



	free(s1.a);

	return 0;
}