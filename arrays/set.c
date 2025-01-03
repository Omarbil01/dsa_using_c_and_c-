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

void set(struct arr *a1, int index,int x)
{
	if(index >= 0 && index < a1->length)
	{
		a1->a[index]=x;
	}
}

int main()
{
	struct arr a1;
	int n,i;
	int w,x;
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

	printf("\nEnter the index: ");
	scanf("%d",&w);

	printf("\nenter the element to change at that index: ");
	scanf("%d",&x);

	set(&a1,w,x);

	display(a1);

	free(a1.a);

	return 0;
}