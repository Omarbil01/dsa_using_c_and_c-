#include<stdio.h>
#include<stdlib.h>

struct arr
{
	int *a;
	int size;
	int length;
};

void display(struct arr a1)
{
	int i;
	printf("Elements are: ");
	for(i=0;i<a1.length;i++)
	{
		printf("%d ",a1.a[i]);
	}
}

int Max(struct arr a1)
{
	int max=a1.a[0];
	int i;
	for(i=1;i<a1.length;i++)
	{
		if(a1.a[i]>max)
		{
			max=a1.a[i];
		}
	}
	return max;
}

int Min(struct arr a1)
{
	int min=a1.a[0];
	int i;
	for(i=1;i<a1.length;i++)
	{
		if(a1.a[i]<min)
		{
			min=a1.a[i];
		}
	}
	return min;
}

int sum(struct arr a1)
{
	int count=0;
	int i;
	for(i=0;i<a1.length;i++)
	{
		count=count + a1.a[i];
	}
	return count;
}

float avg(struct arr a1)
{
	return ((float)sum(a1)/a1.length);
}

int main()
{
	struct arr a1;
	int n,i;
	printf("Enter size of the array: ");
	scanf("%d",&a1.size);
	a1.a=(int *)malloc(a1.size*sizeof(int)); // creating array in heap for c,malloc used for dynamic memory allocation
	a1.length=0;
	printf("Enter amount of number to be inserted in array: ");
	scanf("%d",&n);

	printf("Enter all the elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a1.a[i]);
	}
	a1.length=n;

	display(a1);

	printf("\nmax is %d, min is %d, sum is %d, average is %.2f", Max(a1),Min(a1),sum(a1),avg(a1));

	free(a1.a);
                             
	return 0;
}