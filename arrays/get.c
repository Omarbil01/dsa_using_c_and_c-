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

int get(struct arr a1,int index)
{
	if(index >= 0 && index < a1.length)
	{
		return a1.a[index];
	}
	return -1;
}

int main()
{
	struct arr a1;
	int n,i;
	int w;
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
	printf("\nEnter the element you want to get: ");
	scanf("%d",&w);
	printf("\nElement at index %d is %d",w,get(a1,w));

	free(a1.a);
	return 0;

}
