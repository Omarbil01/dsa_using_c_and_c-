#include<stdio.h>
#include<stdlib.h>

struct element
{
	int i; //row no.
	int j; //column no.
	int x; //non zero element
};

struct sparse
{
	int m; //rows
	int n; //column
	int num; //non zero element
	struct element *ele;
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
    int i, j, k = 0;
    
    for(i = 0; i < s.m; i++)
    {
        for(j = 0; j < s.n; j++)
        {
            if(k < s.num && i == s.ele[k].i && j == s.ele[k].j)
            {
                printf("%d ", s.ele[k++].x);  
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main()
{
	struct sparse s;

	create(&s);
	display(s);

	printf("\n");
	return 0;
}