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

int binsearch(struct arr a1,int low, int high, int key)
{
	int l=low;
	int h=high;
	while(l<=h)
	{
		int mid=((l+h)/2);

		if(key==a1.a[mid])
		{
			return mid;
		}
		else if(key<a1.a[mid])
		{
			return binsearch(a1,low,(mid-1),key);
		}
		else
		{
			return binsearch(a1,(mid+1),high,key);
		}
	}
	return -1;
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

	int lo=0;
	int hi=a1.length - 1;

	int x;
	printf("Enter the number you want to find in the array: ");
	scanf("%d",&x);

	printf("Element found at: %d",binsearch(a1,lo,hi,x));

	free(a1.a);

	return 0;
}
