#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *top=NULL;

void push(int x)
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

int pop()
{
	struct node *t;
	
	int x=-1;

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
	return x;
}

void display()
{
	struct node *p;
	p=top;

	while(p != NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

int prece(char x)
{
	if(x=='+' || x=='-')
	{
		return 1;
	}
	else if(x=='*' || x=='/')
	{
		return 2;
	}
	return 0;
}

int isOperand(char x)
{
	if(x=='+' || x=='-' || x=='*' || x=='/')
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int postf(char *exp)
{
	int i=0,x1,x2,res;

	for(i=0;exp[i] != '\0';i++)
	{
		if(isOperand(exp[i]))
		{
			push(exp[i]-'0');
		}
		else
		{
			x2=pop();
			x1=pop();

			switch(exp[i])
			{
			case '+':
				res=x1+x2;
				break;
			case '-':
				res=x1-x2;
				break;
			case '/':
				res=x1/x2;
				break;
			case '*':
				res=x1*x2;
				break;
			}
			push(res);
		}
	}
	return top->data;
}

int main()
{
	char *postfix="235*+41/+";

	printf("Result is %d\n",postf(postfix));

	return 0;
}