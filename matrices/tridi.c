#include<stdio.h>
#include<stdlib.h>

struct mat
{
	int *a;
	int size;
};

void set(struct mat *m,int i,int j,int x)
{
	if(abs(i-j) <= 1)
	{
		m->a[i*m->size + j]=x;
	}
	else
	{
		m->a[i*m->size + j]=0;
	}
}

void display(struct mat m)
{
	int i,j;
	printf("Matrix is: ");
	for(i=0;i<m.size;i++)
	{
		for(j=0;j<m.size;j++)
		{
			printf("%d ",m.a[i*m.size + j]);
		}
		printf("\n");
	}
}

int main()
{
	struct mat m;
	int i,j;
	int x;

	printf("Enter the size of the matrix: ");
	scanf("%d",&m.size);

	m.a=(int *)malloc(m.size*m.size*sizeof(int));
	if (m.a == NULL) 
	{
        return 1;
    }

	printf("Enter the elements: ");
	for(i=0;i<m.size;i++)
	{
		for(j=0;j<m.size;j++)
		{
			if(abs(i-j)<=1)
			{
				scanf("%d",&x);
			}
			else
			{
				x=0;
			}
			set(&m,i,j,x);
		}
	}

	display(m);

	free(m.a);

	return 0;
}