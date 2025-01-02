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

void insert(struct arr *a1,int index,int value)
{
	int i;
	if(index>=0 && index <= a1->length)
	{
		for(i=a1->length;i>index;i--)
		{
			a1->a[i]=a1->a[i-1];
		}
		a1->a[index]=value;
		a1->length++;
	}
}

int main()
{
	struct arr a1;
	int n,i;
	int x,y;
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

	printf("Enter the array index, the number should be inserted at: ");
	scanf("%d",&x);

	printf("Enter the value to be inserted: ");
	scanf("%d",&y);

	insert(&a1,x,y);
	display(a1);

	free(a1.a);

	return 0;
}
