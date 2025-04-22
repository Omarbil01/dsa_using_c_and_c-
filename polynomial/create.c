#include<stdio.h>
#include<stdlib.h>

struct term
{
	int coeff;
	int exp;
};

struct poly
{
	int n;
	struct term *terms;
};

void create(struct poly *p)
{
	printf("Enter the terms: ");
	scanf("%d",&p->n);

	p->terms=(struct term *)malloc(p->n*sizeof(struct term));

	printf("Enter terms\n: ");
	for(int i=0;i<p->n;i++)
	{
		scanf("%d%d",&p->terms[i].coeff,&p->terms[i].exp);
	}
}

void display(struct poly p)
{
	for(int i=0;i<p.n;i++)
	{
		printf("%dx%d+",p.terms[i].coeff,p.terms[i].exp);
	}
	printf("0");
	printf("\n");
}

int main()
{
	struct poly p1;

	create(&p1);
	display(p1);

	printf("\n");
	return 0;
}