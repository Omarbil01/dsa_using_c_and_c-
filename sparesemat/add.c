#include<stdio.h>
#include<stdlib.h>

struct element
{
	int i; //row no.
	int j; //column no.
	int x; //value of non zero element
};

struct sparse
{
	int m; //total rows
	int n; //total column
	int num; //how many non zero element
	struct element *ele;//values of the non zero elements
};

void create(struct sparse *s)
{
	printf("Enter dimension 1: ");
	scanf("%d",&s->m);
	printf("Enter dimension 2: ");
	scanf("%d",&s->n);

	printf("Number of non zero elements: ");
	scanf("%d",&s->num);

	s->ele=(struct element *)malloc(s->num*sizeof(struct element));
	printf("Enter non zero elements: ");

	for(int i=0;i<s->num;i++)
	{
		scanf("%d%d%d",&s->ele[i].i,&s->ele[i].j,&s->ele[i].x);
	}
}

void display(struct sparse s)
{
	int i,j,k=0;

	for(i=0;i<s.m;i++)
	{
		for(j=0;j<s.n;j++)
		{
			if(i == s.ele[k].i && j== s.ele[k].j)
			{
				printf("%d ",s.ele[k++].x);
			}
			else
			{
				printf("0 ");
			}
		}
		printf("\n");
	}
}

struct sparse * add(struct sparse *s1,struct sparse *s2)
{
	int i,j,k;
	i=j=k=0;
	struct sparse *sum;
	sum=(struct sparse *)malloc(sizeof(struct sparse));

	sum->ele=(struct element *)malloc((s1->num + s2->num) * sizeof(struct element));

	while(i<s1->num && j<s2->num)
	{
		if(s1->ele[i].i<s2->ele[j].i)
		{
			sum->ele[k++]=s1->ele[i++];
		}

		else if(s1->ele[i].i>s2->ele[j].i)
		{
			sum->ele[k++]=s2->ele[j++];
		}

		else
		{
			if(s1->ele[i].j<s2->ele[j].j)
			{
				sum->ele[k++]=s1->ele[i++];
			}

			else if(s1->ele[i].j>s2->ele[j].j)
			{
				sum->ele[k++]=s2->ele[j++];
			}

			else
			{
				sum->ele[k]=s1->ele[i];
				sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
			}
		}
	}

	for(;i<s1->num;i++)
	{
		sum->ele[k++]=s1->ele[i];
	}

	for(;j<s2->num;j++)
	{
		sum->ele[k++]=s2->ele[j];
	}

	sum->m=s1->m;
	sum->n=s1->n;
	sum->num=k;

	return sum;
}

int main()
{
	struct sparse s1,s2,*s3;

	create(&s1);
	create(&s2);

	s3=add(&s1,&s2);

	printf("First Matrix\n");
	display(s1);

	printf("Second Matrix\n");
	display(s2);

	printf("Sum Matrix\n");
	display(*s3);

	printf("\n");
	return 0;
}