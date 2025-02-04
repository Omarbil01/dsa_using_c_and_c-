#include<stdio.h>
#include<stdlib.h>

struct node
{
	char data;
	struct node *next;
};

struct node *top=NULL;

void push(char x)
{
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));

	if(t==NULL)
	{
		printf("Stack is full\n");
	}
	else
	{
		t->data=x;
		t->next=top;
		top=t;
	}
}

void pop()
{
	struct node *t;
	
	char x=-1;

	if(top==NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		t=top;
		x=top->data;
		top=top->next;
		free(t);
	}
}

int isbalanced(char *exp)
{
	int i;
	for(i=0;exp[i]!='\0';i++)
	{
		if(exp[i]=='(')
		{
			push(exp[i]);
		}
		else if(exp[i]==')')
		{
			if(top == NULL)
			{
				return 0;
			}
			pop();
		}
	}
	if(top == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	
	char *exp="((a+b)*(c-d))";

	if(isbalanced(exp)==1)
	{
		printf("Matched\n");
	}
	else
	{
		printf("Not matched");
	}

	return 0;
}