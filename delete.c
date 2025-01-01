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

int delete(struct arr *a1,int index)
{
	int x=0;
	int i;
	if(index>=0 && index<a1->length)
	{
		x=a1->a[index];
		for(i=index;i<a1->length-1;i++)
		{
			a1->a[i]=a1->a[i+1];
		}
		a1->length--;
		return x;
	}
	return 0;
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

	int w;
	printf("Enter the index you want to delete: ");
	scanf("%d",&w);

	printf("%d \n",delete(&a1,w));
	display(a1);

	free(a1.a);

	return 0;
}

