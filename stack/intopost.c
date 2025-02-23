#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

char pop()
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

char * intopost(char *infix)
{
	int i=0;
	int j=0;
	char *postfix;
	int len=strlen(infix);
	postfix=(char *)malloc((len+2)*sizeof(char));

	while(infix[i] != '\0')
	{
		if(isOperand(infix[i]) == 1)
		{
			postfix[j++]=infix[i++];
		}
		else
		{
			if(prece(infix[i])>prece(top->data))
			{
				push(infix[i++]);
			}
			else
			{
				postfix[j++]=pop();
			}
		}
	}

	while(top != NULL)
	{
		postfix[j++]=pop();
	}
	postfix[j]='\0';
	return postfix;

}

int main()
{
	char *infix="a+b*c";
	push('#');
	char *postfix=intopost(infix);

	printf("%s ",postfix);
	printf("\n");
	return 0;
}